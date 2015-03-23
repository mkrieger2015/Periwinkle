#include "TestGOSecond.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"

TestGOSecond::TestGOSecond(std::string modName)
{
	dispGraphicsObject= GameObject::BuildWireframe(modName);
	Initialize();
}

void TestGOSecond::Initialize()
{
	SceneMan::DumpsterRegistration(this);

	CollidableGroup<TestGOSecond>::Register(this);

	Scale.set(.25, .25, .25);
	Rot.set( ROT_XYZ, 0, 0, 0 );
	Trans.set(0, 0, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
	dispGraphicsObject->setWorld(world);

	mainColliderObject= dispGraphicsObject;
	mainColliderCenter= mainColliderObject->getModel()->center;
	mainColliderRadius= mainColliderObject->getModel()->radius;

	//DEBUG
	s= new GraphicsObjectWireFrame(ResourceMan::GetModel("UnitSphere"));
	
}

void TestGOSecond::Update()
{

}

void TestGOSecond::Draw()
{
	dispGraphicsObject->Render();

	//DEBUG FOR DRAWING BOUNDING SPHERE//
	Matrix mAdjust= Matrix(SCALE, dispGraphicsObject->getModel()->radius, dispGraphicsObject->getModel()->radius, dispGraphicsObject->getModel()->radius ) * Matrix(TRANS, dispGraphicsObject->getModel()->center);
	Matrix m= dispGraphicsObject->getWorld();
	m= mAdjust*m;
	s->setWorld(m);
	s->Render();
}

void TestGOSecond::OnDestroy()
{
	
}

TestGOSecond::~TestGOSecond()
{
	CollidableGroup<TestGOSecond>::Deregister(this);
	delete dispGraphicsObject;
	delete s;
}