#include "TestGOSecond.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"
#include "../PeriwinkleEngine/CollisionAABB.h"

TestGOSecond::TestGOSecond(std::string modName)
{
	dispGraphicsObject= GameObject::BuildWireframe(modName);
	Initialize();
}

void TestGOSecond::Initialize()
{

	CollidableGroup<TestGOSecond>::Register(this);

	solid= true;
	Scale.set(.25, .25, .25);
	Rot.set( ROT_XYZ, 0, 0, 0 );
	Trans.set(0, 1, 60);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
	dispGraphicsObject->setWorld(world);

	colVol= new CollisionAABB(dispGraphicsObject);
	colVol->SetVisibility(true);
}

void TestGOSecond::Update()
{
	UpdateCollidable();
}

void TestGOSecond::Draw()
{
	dispGraphicsObject->Render();
	colVol->DrawVolume();
}

void TestGOSecond::OnDestroy()
{
	
}

TestGOSecond::~TestGOSecond()
{
	CollidableGroup<TestGOSecond>::Deregister(this);
	delete dispGraphicsObject;
	delete colVol;
}