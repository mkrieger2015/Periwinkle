#include "TestGOThird.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"
#include "../PeriwinkleEngine/CollisionSphere.h"

TestGOThird::TestGOThird(std::string modName)
{
	dispGraphicsObject= GameObject::BuildWireframe(modName);
	Initialize();
}

void TestGOThird::Initialize()
{

	CollidableGroup<TestGOThird>::Register(this);

	solid= true;
	Scale.set(.25, .25, .25);
	Rot.set( ROT_XYZ, 0, 0, 0 );
	Trans.set(0, 1, -60);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
	dispGraphicsObject->setWorld(world);

	colVol= new CollisionSphere(dispGraphicsObject);
	colVol->SetVisibility(true);
}

void TestGOThird::Update()
{
	UpdateCollidable();
}

void TestGOThird::Draw()
{
	dispGraphicsObject->Render();
	colVol->DrawVolume();
}

void TestGOThird::OnDestroy()
{
	
}

TestGOThird::~TestGOThird()
{
	CollidableGroup<TestGOThird>::Deregister(this);
	delete dispGraphicsObject;
	delete colVol;
}