#ifndef _Spaceship
#define _Spaceship

#include "../PeriwinkleEngine/GameObject.h"
#include <iostream>

class Bullet;

class Spaceship : public GameObject
{
private:
	GraphicsObject *dispGraphicsObject;

public:
	Spaceship(std::string modName);
	~Spaceship();
	void Initialize();
	void OnKeyPress(AZUL_KEY key);
	void Collision( Collidable*) {std::cout << "Test Object 1 and generic collidable" << std::endl;}
	void Update();
	void Draw();
	void OnDestroy();
	Vect ReturnPosition();
};

#endif