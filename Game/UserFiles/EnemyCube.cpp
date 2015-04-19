#include "EnemyCube.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"
#include "../PeriwinkleEngine/CollisionSphere.h"
#include "Bullet.h"

EnemyCube::EnemyCube(std::string modName)
{
	dispGraphicsObject= GameObject::BuildTexturedDefault(modName);
	Initialize();
}

void EnemyCube::Initialize()
{
	solid= false;
	angle= 0;
	Scale.set(1, 1, 1);
	Rot.set(ROT_XYZ, 0,angle,0);
	Trans.set(0, 0, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);

	colVol= new CollisionSphere(dispGraphicsObject);
	dispGraphicsObject->setWorld(world);

	CollidableGroup<EnemyCube>::Register(this);
}

void EnemyCube::Update()
{
	angle += 0.02f;
	Rot.set(ROT_XYZ, 0, angle, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
	dispGraphicsObject->setWorld(world);
	UpdateCollidable();
}

void EnemyCube::Draw()
{
	dispGraphicsObject->Render();
}

void EnemyCube::OnDestroy()
{

}

void EnemyCube::SetPosition(float x, float y, float z)
{
	Trans.set(x, y, z);
}

void EnemyCube::Collision(Bullet*)
{
	MarkForDestroy();
}

EnemyCube::~EnemyCube()
{
	CollidableGroup<EnemyCube>::Deregister(this);
	delete dispGraphicsObject;
	delete colVol;
}

