#ifndef _EnemyCube
#define _EnemyCube

#include "../PeriwinkleEngine/GameObject.h"
#include <iostream>

class Bullet;

class EnemyCube : public GameObject
{
private:
	GraphicsObject *dispGraphicsObject;
	float angle;
	GraphicsObject *s;

public:
	EnemyCube(std::string modName);
	~EnemyCube();
	void Initialize();
	void Collision( Collidable*) {std::cout << "Test Object 1 and generic collidable" << std::endl;}
	void Collision( Bullet*);
	void Update();
	void Draw();
	void OnDestroy();
	void SetPosition(float x, float y, float z);
};

#endif