#include "TestScene.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/CollisionMan.h"
#include "TestGO.h"
#include "TestGOSecond.h"
#include "TestGOThird.h"
#include "Plane.h"
#include "CameraMan.h"
#include "../PeriwinkleEngine/Game.h"

void TestScene::LoadContentScene()
{
	// Camera Setup ---------------------------------------
	// Initially setup the camera
	CameraMan::GetCurrent()->setViewport(0, 0, Game::windowWidth(), Game::windowHeight());
	CameraMan::GetCurrent()->setPerspective( 45, float(Game::windowWidth())/float(Game::windowHeight()), 1, 5000);

	// Position and Orient Camera
	Vect up(0,1,0);
	Vect pos(0,100,150);
	Vect lookAt(0,0,0);
	CameraMan::GetCurrent()->setOrientAndPosition( up, lookAt, pos);

	CameraMan::GetCurrent()->updateCamera();

	Plane *plane;
	plane= new Plane("Grid", "Plane");

	TestGO *testObj;
	testObj= new TestGO("spaceFrigate", "spaceFrigate");

	TestGOSecond *testObj2;
	testObj2= new TestGOSecond("spaceFrigate");

	TestGOThird *testObj3;
	testObj3= new TestGOThird("spaceFrigate");

	cm->SetCollisionPair<TestGO,TestGOSecond>();
	cm->SetCollisionPair<TestGO,TestGOThird>();
}
