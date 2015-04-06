#include "Spaceship.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"
#include "Bullet.h"

Spaceship::Spaceship(std::string modName)
{
	dispGraphicsObject= GameObject::BuildTexturedDefault(modName);
	Initialize();
}

void Spaceship::Initialize()
{
	Scale.set(.25, .25, .25);
	Rot.set(ROT_XYZ, -90*(MATH_PI/180), 180*(MATH_PI/180), 0);
	Trans.set(0, -50, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);

	dispGraphicsObject->setWorld(world);

	RegisterKeyPress(AZUL_KEY::KEY_SPACE);

	mainColliderObject= dispGraphicsObject;
	mainColliderCenter= mainColliderObject->getModel()->center;
	mainColliderRadius= mainColliderObject->getModel()->radius;
}

void Spaceship::OnKeyPress(AZUL_KEY key)
{
	if(key == AZUL_KEY::KEY_SPACE)
	{
		new Bullet("UnitSphere", this);
	}
}

void Spaceship::Update()
{
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

void Spaceship::Draw()
{
	dispGraphicsObject->Render();
}

void Spaceship::OnDestroy()
{
	
}

Spaceship::~Spaceship()
{
	delete dispGraphicsObject;
}

Vect Spaceship::ReturnPosition()
{
	return Trans;
}