#include "TestGO.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"
#include "../PeriwinkleEngine/CollisionAABB.h"
#include "../PeriwinkleEngine/CameraObject.h"

#include "ShooterScene.h"

TestGO::TestGO(std::string texName, std::string modName)
{
	dispGraphicsObject= GameObject::BuildTextured(texName, modName);
	Initialize();
}

void TestGO::Initialize()
{
	solid= false;
	Scale.set(.5, .5, .5);
	Rot.set(ROT_XYZ, 0, 0, 0);
	Trans.set(0, 6, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);

	dispGraphicsObject->setWorld(world);

	RegisterKeyPress(AZUL_KEY::KEY_Z);
	RegisterKeyPress(AZUL_KEY::KEY_X);
	RegisterKeyPress(AZUL_KEY::KEY_A);
	RegisterKeyPress(AZUL_KEY::KEY_S);
	CollidableGroup<TestGO>::Register(this);

	colVol= new CollisionAABB(dispGraphicsObject);
	colVol->SetVisibility(true);

	cam= NULL;

	
	camUp= Vect(0,1,0);
	camPos= Trans;
	camPos += Vect(0, 150, -50);
	camTarget= Trans;
	
	cam= new CameraObject(&camUp, &camPos, &camTarget);
	
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
	bool moved;
	moved= false;

	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_UP))
	{
		Trans += Vect(0,0,1) * Rot;
		moved= true;
	}
	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_DOWN))
	{
		Trans -= Vect(0,0,1) * Rot;
		moved= true;
	}
	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_LEFT))
	{
		Rot *= Matrix( ROT_Y, .05f );
		moved= true;
	}
	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_RIGHT))
	{
		Rot *= Matrix( ROT_Y, -.05f );
		moved= true;
	}

	if(moved == true)
	{
		world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
		dispGraphicsObject->setWorld(world);

		camUp= Vect(0,1,0);
		camPos= Trans;
		camPos += Vect(0, 150, -50);
		camTarget= Trans;
	
		cam->CamUpdate(&camUp, &camPos, &camTarget);
		
	}

	UpdateCollidable();
}

void TestGO::Draw()
{
	dispGraphicsObject->Render();
	colVol->DrawVolume();
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

void TestGO::Collision( TestGOThird*)
{
	SceneMan::NextScene(new ShooterScene());
}


TestGO::~TestGO()
{
	CollidableGroup<TestGO>::Deregister(this);
	delete dispGraphicsObject;
	delete colVol;
	delete cam;
}