#include "../PeriwinkleEngine/Game.h"

#include "../PeriwinkleEngine/ResourceMan.h"
#include "../PeriwinkleEngine/KeyboardMan.h"
#include "../PeriwinkleEngine/SceneMan.h"
#include "../PeriwinkleEngine/GameObject.h"
#include "../PeriwinkleEngine/TimeMan.h"
#include "../PeriwinkleEngine/CollisionMan.h"
#include "TestScene.h"
#include "ShooterScene.h"

void Game::InitializeContext()
{
	Scene* mainScene= new TestScene();
	SceneMan::SetCurScene(mainScene);
	SceneMan::InitializeCurScene();
}

void Game::LoadGameContent()
{
	ResourceMan::LoadAllContent();
	SceneMan::LoadContentCurScene();
}

void Game::UnloadGameContent()
{

}

void Game::TerminateContext()
{

}