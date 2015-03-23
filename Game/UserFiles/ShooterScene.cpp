#include "ShooterScene.h"
#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/CollisionMan.h"
#include "CameraMan.h"
#include "../PeriwinkleEngine/Game.h"
#include "Spaceship.h"
#include "EnemyCube.h"
#include "Bullet.h"

void ShooterScene::LoadContentScene()
{
	Spaceship *player;
	player= new Spaceship("spaceFrigate");

	EnemyCube *enemy1;
	EnemyCube *enemy2;
	EnemyCube *enemy3;
	enemy1= new EnemyCube("Cottage");
	enemy1->SetPosition(-40,40,0);
	
	enemy2= new EnemyCube("Cottage");
	enemy2->SetPosition(0,40,0);

	enemy3= new EnemyCube("Cottage");
	enemy3->SetPosition(40,40,0);

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

	cm->SetCollisionPair<Bullet,EnemyCube>();
}
