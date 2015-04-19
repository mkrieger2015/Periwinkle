#include "CollisionAABB.h"
#include "CollisionSphere.h"
#include "ResourceMan.h"

CollisionAABB::CollisionAABB(GraphicsObject *obj)
{
	drawn= false;
	collisionMesh= NULL;
	collisionModel= obj;
	minPoint= Vect(0,0,0);
	maxPoint= Vect(0,0,0);
	UpdateVolume();
}

CollisionAABB::~CollisionAABB()
{
	if(collisionMesh != NULL)
		delete collisionMesh;
}

void CollisionAABB::UpdateVolume()
{
	Vect* vectArray;
	vectArray= collisionModel->getModel()->getVectList();

	Vect tempVect;
	tempVect= vectArray[0]*(collisionModel->getWorld());

	float maxX= tempVect[x];
	float maxY= tempVect[y];
	float maxZ= tempVect[z];
	float minX= tempVect[x]; 
	float minY= tempVect[y];
	float minZ= tempVect[z];

	for(int i=0; i < collisionModel->getModel()->numVerts; i++)
	{
		tempVect= vectArray[i]*(collisionModel->getWorld());
		if(tempVect[x] < minX)
			minX= tempVect[x];
		if(tempVect[y] < minY)
			minY= tempVect[y];
		if(tempVect[z] < minZ)
			minZ= tempVect[z];
		if(tempVect[x] > maxX)
			maxX= tempVect[x];
		if(tempVect[y] > maxY)
			maxY= tempVect[y];
		if(tempVect[z] > maxZ)
			maxZ= tempVect[z];
	}

	minPoint= Vect(minX, minY, minZ);
	maxPoint= Vect(maxX, maxY, maxZ);
}

Vect CollisionAABB::ReturnAABBScale()
{
	return minPoint - maxPoint;
}

Vect CollisionAABB::ReturnAABBCenter()
{
	Vect ret= minPoint + maxPoint;
	ret[x] /= 2;
	ret[y] /= 2;
	ret[z] /= 2;

	return ret;
}

bool CollisionAABB::Accept(CollisionVolume *other)
{
	return other->AABBVisit(this);
}

bool CollisionAABB::Visit(CollisionVolume *other)
{
	(void)other;
	return false;
}

bool CollisionAABB::SphereVisit(CollisionSphere *other)
{
	Vect clampedCenter= other->ReturnSphereCenter();

	if(clampedCenter[x] >= minPoint[x] && clampedCenter[x] <= maxPoint[x] && clampedCenter[y] >= minPoint[y] && clampedCenter[y] <= maxPoint[y] && clampedCenter[z] >= minPoint[z] && clampedCenter[z] <= maxPoint[z])
		return true;

	if(clampedCenter[x] < minPoint[x])
		clampedCenter[x]= minPoint[x];
	else if(clampedCenter[x] > maxPoint[x])
		clampedCenter[x]= maxPoint[x];
	if(clampedCenter[y] < minPoint[y])
		clampedCenter[y]= minPoint[y];
	else if(clampedCenter[y] > maxPoint[y])
		clampedCenter[y]= maxPoint[y];
	if(clampedCenter[z] < minPoint[z])
		clampedCenter[z]= minPoint[z];
	else if(clampedCenter[z] > maxPoint[z])
		clampedCenter[z]= maxPoint[z];

	if(Vect(clampedCenter - other->ReturnSphereCenter()).mag() <= other->ReturnSphereRadius())
	{
		return true;
	}
	return false;
}

bool CollisionAABB::AABBVisit(CollisionAABB *other)
{
	bool xPass= false;
	bool yPass= false;
	bool zPass= false;

	int xChecks= 0;
	int yChecks= 0;
	int zChecks= 0;

	Vect otherMin= other->ReturnMinPoint();
	Vect otherMax= other->ReturnMaxPoint();

	if(minPoint[x] >= otherMin[x] && minPoint[x] <= otherMax[x])
		xPass++;
	if(maxPoint[x] >= otherMin[x] && maxPoint[x] <= otherMax[x])
		xPass++;
	if(otherMin[x] >= minPoint[x] && otherMin[x] <= maxPoint[x])
		xPass++;
	if(otherMax[x] >= minPoint[x] && otherMax[x] <= maxPoint[x])
		xPass++;

	if(minPoint[y] >= otherMin[y] && minPoint[y] <= otherMax[y])
		yPass++;
	if(maxPoint[y] >= otherMin[y] && maxPoint[y] <= otherMax[y])
		yPass++;
	if(otherMin[y] >= minPoint[y] && otherMin[y] <= maxPoint[y])
		yPass++;
	if(otherMax[y] >= minPoint[y] && otherMax[y] <= maxPoint[y])
		yPass++;

	if(minPoint[z] >= otherMin[z] && minPoint[z] <= otherMax[z])
		zPass++;
	if(maxPoint[z] >= otherMin[z] && maxPoint[z] <= otherMax[z])
		zPass++;
	if(otherMin[z] >= minPoint[z] && otherMin[z] <= maxPoint[z])
		zPass++;
	if(otherMax[z] >= minPoint[z] && otherMax[z] <= maxPoint[z])
		zPass++;

	if(xChecks > 0)
		xPass= true;
	if(yChecks > 0)
		yPass= true;
	if(zChecks > 0)
		zPass= true;

	if(xPass == true && yPass == true && zPass == true)
		return true;
	else
		return false;
}

void CollisionAABB::SetVisibility(bool v)
{
	if(v == true && drawn == false)
	{
		drawn= true;
		collisionMesh= new GraphicsObjectWireFrame(ResourceMan::GetModel("UnitCube"));
	}
	else if (v == false && drawn == true)
	{
		drawn= false;
		delete collisionMesh;
	}
}

void CollisionAABB::DrawVolume()
{
	if(drawn == true)
	{
		Matrix m= Matrix(SCALE, (minPoint - maxPoint))*Matrix(TRANS, (ReturnAABBCenter()));
		collisionMesh->setWorld(m);
		collisionMesh->Render();
	}
}