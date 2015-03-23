#ifndef _TestGOSecond
#define _TestGOSecond

#include "../PeriwinkleEngine/GameObject.h"

class TestGO;

class TestGOSecond : public GameObject
{
private:
	GraphicsObject *dispGraphicsObject;
	GraphicsObjectWireFrame *s;
public:
	TestGOSecond(std::string modName);
	~TestGOSecond();
	void Initialize();
	void Update();
	void Collision( Collidable*) {std::cout << "Test Object 2 and generic collidable" << std::endl;}
	void Collision( TestGO*) {};
	void Draw();
	void OnDestroy();
};

#endif