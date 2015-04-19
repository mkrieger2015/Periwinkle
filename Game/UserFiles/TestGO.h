#ifndef _TestGO
#define _TestGO

#include "../PeriwinkleEngine/GameObject.h"
#include <iostream>

class CameraObject;
class TestGOSecond;
class TestGOThird;

class TestGO : public GameObject
{
private:
	GraphicsObject *dispGraphicsObject;

	CameraObject *cam;

	Vect camUp;
	Vect camDir;
	Vect camPos;
	Vect camTarget;
	Matrix camRot;
public:
	TestGO(std::string texName, std::string modName);
	~TestGO();
	void Initialize();
	void OnKeyPress(AZUL_KEY key);
	void Update();
	void Alarm0();
	void Alarm1();
	void Collision( Collidable*) {std::cout << "Test Object 1 and generic collidable" << std::endl;}
	void Collision( TestGOSecond*);
	void Collision( TestGOThird*);
	void Draw();
	void OnDestroy();
};

#endif