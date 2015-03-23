#ifndef _Bullet
#define _Bullet

#include "../PeriwinkleEngine/GameObject.h"
#include <iostream>

class Spaceship;
class EnemyCube;

class Bullet : public GameObject
{
private:
	GraphicsObject *dispGraphicsObject;

public:
	Bullet(std::string modName, Spaceship *player);
	~Bullet();
	void Initialize();
	void Collision( Collidable*) {std::cout << "Test Object 1 and generic collidable" << std::endl;}
	void Collision( EnemyCube*);
	void Update();
	void Draw();
	void Alarm0();
	void OnDestroy();
};

#endif