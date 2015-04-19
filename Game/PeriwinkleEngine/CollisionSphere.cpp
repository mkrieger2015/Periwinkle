#include "CollisionSphere.h"
#include "CollisionAABB.h"
#include "ResourceMan.h"

CollisionSphere::CollisionSphere(GraphicsObject *obj)
{
	drawn= false;
	collisionMesh= NULL;
	object= obj;
	radius= obj->getModel()->radius;
	center= obj->getModel()->center;
	UpdateVolume();
}

CollisionSphere::~CollisionSphere()
{
	if(collisionMesh != NULL)
		delete collisionMesh;
}


void CollisionSphere::UpdateVolume()
{
	worldAdjust= (Matrix(SCALE, radius, radius, radius) * Matrix(TRANS, center))*(object->getWorld());

	Vect centerBase= Vect(0,0,0);
	Vect radiusBase= Vect(1,0,0);

	centerAdjust= centerBase*worldAdjust;

	radiusAdjust= Vect(centerAdjust - Vect(radiusBase*worldAdjust)).mag();
}

bool CollisionSphere::Accept(CollisionVolume *other)
{
	return other->SphereVisit(this);
}

bool CollisionSphere::Visit(CollisionVolume *other)
{
	(void)other;
	return false;
}

bool CollisionSphere::SphereVisit(CollisionSphere *other)
{
	float centerDist;
	centerDist= Vect(centerAdjust - other->centerAdjust).mag();
	float radiusSum;
	radiusSum= radiusAdjust + other->radiusAdjust;

	if(centerDist <= radiusSum)
	{
		return true;
	}
		return false;
}

bool CollisionSphere::AABBVisit(CollisionAABB *other)
{
	Vect clampedCenter= centerAdjust;
	Vect minPoint= other->ReturnMinPoint();
	Vect maxPoint= other->ReturnMaxPoint();

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

	if(Vect(clampedCenter - centerAdjust).mag() <= radiusAdjust)
	{
		return true;
	}
	return false;
}

void CollisionSphere::SetVisibility(bool v)
{
	if(v == true && drawn == false)
	{
		drawn= true;
		collisionMesh= new GraphicsObjectWireFrame(ResourceMan::GetModel("UnitSphere"));
	}
	else if (v == false && drawn == true)
	{
		drawn= false;
		delete collisionMesh;
	}
}

void CollisionSphere::DrawVolume()
{
	if(drawn == true)
	{
		collisionMesh->setWorld(worldAdjust);
		collisionMesh->Render();
	}
}