#include "Game.h"

#include "ResourceMan.h"
#include "KeyboardMan.h"
#include "SceneMan.h"
#include "GameObject.h"
#include "TimeMan.h"
#include "CollisionMan.h"

Game* Game::ptrGame;
int Game::winHeight;
int Game::winWidth;


//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
Game::Game( const char * const windowName, int widthScreen, int heightScreen )
: Engine( windowName, widthScreen, heightScreen)
{
	ptrGame= this;
	printf("Game(): started\n");
	glfwSetWindowPos(this->window, 20, 30);
	winHeight= this->screenHeight;
	winWidth= this->screenWidth;
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{
	TimeMan::Initialize();
	SceneMan::Initialize();

	InitializeContext();
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	LoadGameContent();
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update()
{
		TimeMan::Update();
		SceneMan::CheckScene();
		SceneMan::UpdateCurAlarmables();
		SceneMan::UpdateCurInputables();
		SceneMan::UpdateCurUpdateables();
		SceneMan::UpdateCurCollidables();
		SceneMan::DestroyMarked();
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{ 
	SceneMan::UpdateCurDrawables();
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//       (also used to clean up whatever was created in Game::Initialize()  )
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
	UnloadGameContent();

	ResourceMan::UnloadAll();
	TimeMan::Delete();
	SceneMan::UnloadAll();

	TerminateContext();
}

int Game::windowHeight()
{
	return winHeight;
}

int Game::windowWidth()
{
	return winWidth;
}
// End of Game.cpp
