#ifndef GAME_H
#define GAME_H

#include "Azul.h"
#include "GameObject.h"

///
///\class	Game
///\ingroup PeriwinkleEngine
///\brief	Main game class. If you think you should put something in here, double check before you do - you probably shouldn't.
///
///\author	Max Krieger
///\date	3/4/2015
///
class Game : public Engine
{

public:
	///
	///\fn	Game::Game( const char * const windowName, int widthScreen, int heightScreen );
	///
	///\brief	Constructor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	windowName  	Name of the window.
	///\param	widthScreen 	Screen width in pixels.
	///\param	heightScreen	Screen height in pixels.
	///
	Game( const char * const windowName, int widthScreen, int heightScreen );

	///
	///\fn	static int Game::windowHeight();
	///
	///\brief	Returns window height. Public accessor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\return	An int.
	///
	static int windowHeight();

	///
	///\fn	static int Game::windowWidth();
	///
	///\brief	Returns window width. Public accessor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\return	An int.
	///
	static int windowWidth();

	///\brief	Height of the window.
	static int winHeight;

	///\brief	Width of the window.
	static int winWidth;
	

private:

	///\brief	Game's pointer to itself.
	static Game* ptrGame;

	///
	///\fn	void Game::Initialize() override;
	///
	///\brief	Initialization step. Very first thing called, called once on startup.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void Initialize() override;

	///
	///\fn	void Game::LoadContent() override;
	///
	///\brief	Content-loading step. Called once on startup, after initialization.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void LoadContent() override;

	///
	///\fn	void Game::Update() override;
	///
	///\brief	Update step. Called per-frame.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void Update() override;

	///
	///\fn	void Game::Draw() override;
	///
	///\brief	Draw step. Called per-frame, after Update.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void Draw() override;

	///
	///\fn	void Game::UnLoadContent() override;
	///
	///\brief	Content unloading/memory cleanup phase. Called once on shutdown.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void UnLoadContent() override;

	///
	///\fn	virtual void Game::InitializeContext();
	///
	///\brief	User-defined event called during initialization step. Defined in User Game Prefs.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void InitializeContext();

	///
	///\fn	virtual void Game::LoadGameContent();
	///
	///\brief	User-defined event called during content loading step. Defined in User Game Prefs.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void LoadGameContent();

	///
	///\fn	virtual void Game::UnloadGameContent();
	///
	///\brief	User-defined event called during the content unloading/memory cleanup step. Defined in User Game Prefs.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void UnloadGameContent();

	///
	///\fn	virtual void Game::TerminateContext();
	///
	///\brief	User-defined event called at the VERY END of the content unloading/memory cleanup step. Defined in User Game Prefs.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void TerminateContext();
};



#endif 