///
///\file	Doxygen Group Header\DoxygenGroups.h
///
///\brief	This is a simple storage file for all Doxygen groups, and the main page. Not part of the game engine.
///





///\mainpage Periwinkle Engine v 0.5 FAQ
///\section YO Introduction
///         Welcome to the Periwinkle wiki! This page will give you a brief rundown on how to organize your project in Periwinkle.
///\section HI Where To Put Your Files
///         We recommend that you put your files in the "User Files" filter within a Periwinkle base project.
///         Within that filter, there is a sub-filter called "User Game Prefs." 
///         This contains a file where you define things you wish to happen during the game's initialization, content load, content unload, and shutdown phase.
///         In addition, there is a filter for your scenes calls Scenes (User).
///         Feel free to add any additional filters as you see fit.
///\section HEYO Asset Loading
///          In the "Content" filter, there is a single file, LoadAllResources. 
///          The example project demonstrates to you how to load in your game resources with this file.
///          It is recommended that you do all resource loading there (e.g. if you're not an advanced user, don't do it anywhere else!)
///\section WASSUP I got an Abort() Crash! What does it mean? Help!
///          If you got an abort() crash, this means AZUL has failed to load your model or texture from the filename you specified. 
///\section HOLA Helpful Managers to Know
///          These are the most basic managers you need to be aware of if you're using Periwinkle for the first time.
///          SceneMan : The scene manager. This is the manager you'll call to access a scene's individual managers. It's a singleton, so PLEASE, access a scene's managers through its static wrappers!
///          TimeMan : Another singleton that can return your frame time or total run time. Useful for time-related features or FPS counters.
///          ResourceMan : This is the manager which stores all of your textures and models (more types of resources forthcoming). Use it to build GraphicsObjects.


///
/// \defgroup     PerwinkleEngine
///
/// \brief        This group contains all source code for the Periwinkle game engine, though it does not contain the source for GLFW or the TEAL framework.
///

///
/// \defgroup     GameObject
/// \ingroup      PerwinkleEngine
/// \brief        This group contains the GameObject, as well as its parent "-able" classes.
///

///
/// \defgroup     Input
/// \ingroup      GameObject
/// \brief        This group contains all classes relevant to Input in a GameObject.
///

///
/// \defgroup     Draw
/// \ingroup      GameObject
/// \brief        This group contains all classes relevant to Drawing in a GameObject.
///

///
/// \defgroup     Update
/// \ingroup      GameObject
/// \brief        This group contains all classes relevant to Input on a GameObject.
///

///
/// \defgroup     Collisions
/// \ingroup      GameObject
/// \brief        This group contains all classes relevant to Collisions on a GameObject.
///

///
/// \defgroup     Alarms
/// \ingroup      GameObject
/// \brief        This group contains all classes relevant to Alarms on a GameObject.
///

///
/// \defgroup     Terimination
/// \ingroup      GameObject
/// \brief        This group contains all classes relevant to Alarms on a GameObject.
///

///
/// \defgroup     Scene
/// \ingroup      PeriwinkleEngine
/// \brief        This group contains everything related to Scenes - class, their manager, and their various sub-managers.
///

/// 
/// \defgroup     Managers
/// \ingroup      Scene
/// \brief        This group contains a scene's various per-scene managers.

///
/// \defgroup     Resources
/// \ingroup      PeriwinkleEngine
/// \brief        This group contains all classes in charge of managing resources, such as models and textures.
///

///
/// \defgroup     Time
/// \ingroup      PeriwinkleEngine
/// \brief        This group contains all classes in charge of managing time, used throughout the engine.
///