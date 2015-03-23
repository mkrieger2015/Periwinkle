#include "TestScene.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/CollisionMan.h"
#include "TestGO.h"
#include "TestGOSecond.h"
#include "CameraMan.h"
#include "../PeriwinkleEngine/Game.h"

void TestScene::LoadContentScene()
{
	TestGO *testObj;
	testObj= new TestGO("spaceFrigate", "spaceFrigate");

	TestGOSecond *testObj2;
	testObj2= new TestGOSecond("spaceFrigate");

	cm->SetCollisionPair<TestGO,TestGOSecond>();

	// Camera Setup ---------------------------------------
	// Initially setup the camera
	CameraMan::GetCurrent()->setViewport(0, 0, Game::windowWidth(), Game::windowHeight());
	CameraMan::GetCurrent()->setPerspective( 45, float(Game::windowWidth())/float(Game::windowHeight()), 1, 5000);

	// Position and Orient Camera
	Vect up(0,1,0);
	Vect pos(0,0,150);
	Vect lookAt(0,0,0);
	CameraMan::GetCurrent()->setOrientAndPosition( up, lookAt, pos);

	// Computes all the parameters for the camera
	//   Note: This demo has a fixed camera so no need to repeat the update
	CameraMan::GetCurrent()->updateCamera();
}
