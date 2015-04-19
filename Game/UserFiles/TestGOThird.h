#ifndef _TestGOThird
#define _TestGOThird

#include "../PeriwinkleEngine/GameObject.h"

class TestGO;

class TestGOThird : public GameObject
{
private:
	GraphicsObject *dispGraphicsObject;
public:
	TestGOThird(std::string modName);
	~TestGOThird();
	void Initialize();
	void Update();
	void Collision( Collidable*) {std::cout << "Test Object 3 and generic collidable" << std::endl;}
	void Collision( TestGO*) {};
	void Draw();
	void OnDestroy();
};

#endif