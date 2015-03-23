#include "EnemyCube.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"
#include "Bullet.h"

EnemyCube::EnemyCube(std::string modName)
{
	dispGraphicsObject= GameObject::BuildTexturedDefault(modName);
	Initialize();
}

void EnemyCube::Initialize()
{
	angle= 0;
	Scale.set(1, 1, 1);
	Rot.set(ROT_XYZ, 0,angle,0);
	Trans.set(0, 0, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);

	dispGraphicsObject->setWorld(world);

	SceneMan::DumpsterRegistration(this);

	CollidableGroup<EnemyCube>::Register(this);

	mainColliderObject= dispGraphicsObject;
	mainColliderCenter= mainColliderObject->getModel()->center;
	mainColliderRadius= mainColliderObject->getModel()->radius;
}

void EnemyCube::Update()
{
	angle += 0.02f;
	Rot.set(ROT_XYZ, 0, angle, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
	dispGraphicsObject->setWorld(world);
}

void EnemyCube::Draw()
{
	dispGraphicsObject->Render();
}

void EnemyCube::OnDestroy()
{
	SceneMan::DumpsterDeregistration(this);
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
}

