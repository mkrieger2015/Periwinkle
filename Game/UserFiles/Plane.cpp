#include "Plane.h"
#include "../PeriwinkleEngine/CollisionSphere.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"

Plane::Plane(std::string texName, std::string modName)
{
	dispGraphicsObject= GameObject::BuildTextured(texName, modName);
	Initialize();
}

void Plane::Initialize()
{
	solid= true;
	colVol= NULL;	
	Scale.set(400, 400, 400);
	Rot.set( ROT_XYZ, 0, 0, 0 );
	Trans.set(0, 0, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
	dispGraphicsObject->setWorld(world);
}

void Plane::Draw()
{
	dispGraphicsObject->Render();
}

void Plane::OnDestroy()
{
	
}

Plane::~Plane()
{
	delete dispGraphicsObject;
}