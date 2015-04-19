#ifndef _Plane
#define _Plane
#include "../PeriwinkleEngine/GameObject.h"

class TestGO;

class Plane : public GameObject
{
private:
	GraphicsObject *dispGraphicsObject;
public:
	Plane(std::string texName, std::string modName);
	~Plane();
	void Initialize();
	void Draw();
	void OnDestroy();
};

#endif