#include "Spaceship.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/CollidableGroup.h"
#include "../PeriwinkleEngine/CollisionSphere.h"
#include "Bullet.h"

Spaceship::Spaceship(std::string modName)
{
	dispGraphicsObject= GameObject::BuildTexturedDefault(modName);
	Initialize();
}

void Spaceship::Initialize()
{
	solid= false;
	Scale.set(.25, .25, .25);
	Rot.set(ROT_XYZ, -90*(MATH_PI/180), 180*(MATH_PI/180), 0);
	Trans.set(0, -50, 0);
	world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);

	dispGraphicsObject->setWorld(world);

	RegisterKeyPress(AZUL_KEY::KEY_SPACE);

	colVol= new CollisionSphere(dispGraphicsObject);
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
	bool moved;
	moved= false;

	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_LEFT))
	{
		Trans -= Vect(1,0,0);
		moved= true;
	}
	if(InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_RIGHT))
	{
		Trans += Vect(1,0,0);
		moved= true;
	}

	if(moved == true)
	{
		world = Matrix(SCALE,Scale) * Rot * Matrix(TRANS,Trans);
		dispGraphicsObject->setWorld(world);
	}

	UpdateCollidable();
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
	delete colVol;
}

Vect Spaceship::ReturnPosition()
{
	return Trans;
}