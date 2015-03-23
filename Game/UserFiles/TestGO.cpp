#include "TestGO.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"
#include "ShooterScene.h"

TestGO::TestGO(std::string texName, std::string modName)
{
	dispGraphicsObject= GameObject::BuildTextured(texName, modName);
	Initialize();
}

void TestGO::Initialize()
{
	Scale.set(.5, .5, .5);
	Rot.set(ROT_XYZ, 45, 45, 0);
	Trans.set(40, 0, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);

	dispGraphicsObject->setWorld(world);

	SceneMan::DumpsterRegistration(this);

	RegisterKeyPress(AZUL_KEY::KEY_Z);
	RegisterKeyPress(AZUL_KEY::KEY_X);
	RegisterKeyPress(AZUL_KEY::KEY_A);
	RegisterKeyPress(AZUL_KEY::KEY_S);
	CollidableGroup<TestGO>::Register(this);

	mainColliderObject= dispGraphicsObject;
	mainColliderCenter= mainColliderObject->getModel()->center;
	mainColliderRadius= mainColliderObject->getModel()->radius;

	//DEBUG
	s= new GraphicsObjectWireFrame(ResourceMan::GetModel("UnitSphere"));
}

void TestGO::OnKeyPress(AZUL_KEY key)
{
	if(key == AZUL_KEY::KEY_Z)
	{
		SetAlarm(0,5);
		std::cout << "Test object sez: Alarm 0 will quack in 5 seconds!" << std::endl;
	}
	else if(key == AZUL_KEY::KEY_X)
	{
		ClearAlarm(0);
		std::cout << "Test object sez: Nah, just kidding. Alarm 0 cancelled." << std::endl;
	}
	else if(key == AZUL_KEY::KEY_A)
	{
		SetAlarm(1,5.8f);
		std::cout << "Test object sez: Alarm 1 will honk in 5.8 seconds!" << std::endl;
	}
	else if(key == AZUL_KEY::KEY_S)
	{
		ClearAlarm(1);
		std::cout << "Test object sez: Nah, just kidding. Alarm 1 cancelled." << std::endl;
	}

}

void TestGO::Alarm0()
{
	std::cout << "Alarm 0 sez: QUACK!" << std::endl;
}

void TestGO::Alarm1()
{
	std::cout << "Alarm 1 sez: HONK!" << std::endl;
}

void TestGO::Update()
{
	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_UP))
	{
		Trans += Vect(0,1,0);
	}
	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_DOWN))
	{
		Trans -= Vect(0,1,0);
	}
	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_LEFT))
	{
		Trans -= Vect(1,0,0);
	}
	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_RIGHT))
	{
		Trans += Vect(1,0,0);
	}

	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
	dispGraphicsObject->setWorld(world);
}

void TestGO::Draw()
{
	dispGraphicsObject->Render();

	//DEBUG FOR DRAWING BOUNDING SPHERE//
	Matrix mAdjust= Matrix(SCALE, dispGraphicsObject->getModel()->radius, dispGraphicsObject->getModel()->radius, dispGraphicsObject->getModel()->radius ) * Matrix(TRANS, dispGraphicsObject->getModel()->center);
	Matrix m= dispGraphicsObject->getWorld();
	m= mAdjust*m;

	s->setWorld(m);
	s->Render();
}

void TestGO::OnDestroy()
{
	ClearAlarm(0);
	ClearAlarm(1);
	ClearAlarm(2);
}

void TestGO::Collision( TestGOSecond*)
{
	SceneMan::NextScene(new ShooterScene());
}

TestGO::~TestGO()
{
	CollidableGroup<TestGO>::Deregister(this);
	delete dispGraphicsObject;
	delete s;
}