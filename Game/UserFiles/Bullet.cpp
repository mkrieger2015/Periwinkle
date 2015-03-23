#include "Bullet.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"
#include "Spaceship.h"

Bullet::Bullet(std::string modName, Spaceship *player)
{
	dispGraphicsObject= GameObject::BuildWireframe(modName);
	Initialize();
	Trans= player->ReturnPosition();
}

void Bullet::Initialize()
{
	SetAlarm(0,2);
	Scale.set(2, 2, 2);
	Rot.set(ROT_XYZ, 0,0,0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);

	dispGraphicsObject->setWorld(world);

	SceneMan::DumpsterRegistration(this);

	CollidableGroup<Bullet>::Register(this);

	mainColliderObject= dispGraphicsObject;
	mainColliderCenter= mainColliderObject->getModel()->center;
	mainColliderRadius= mainColliderObject->getModel()->radius;
}

void Bullet::Update()
{
	Trans += Vect(0,2,0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
	dispGraphicsObject->setWorld(world);
}

void Bullet::Draw()
{
	dispGraphicsObject->Render();
}

void Bullet::Alarm0()
{
	MarkForDestroy();
}

void Bullet::OnDestroy()
{
	ClearAlarm(0);
	SceneMan::DumpsterDeregistration(this);
}

Bullet::~Bullet()
{
	CollidableGroup<Bullet>::Deregister(this);
	delete dispGraphicsObject;
}

void Bullet::Collision(EnemyCube*)
{
	MarkForDestroy();
}