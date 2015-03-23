#ifndef _SceneMan
#define _SceneMan

#include "Azul.h"
#include "Scene.h"
#include <list>
#include <string>

class GameObject;
class Drawable;
class Inputable;
class Updateable;
class Alarmable;
class Terminable;
class Dumpster;

///
///\class	SceneMan
///\ingroup Scene
///\brief	Singleton manager for all scenes. The user-level accessor for all non-singleton, per-scene manager registration/deregistration/updates, as well as switching scenes.
///
///\author	Max Krieger
///\date	3/5/2015
///
class SceneMan
{
private:


	///\brief	The self pointer for singleton accessor.
	static SceneMan *self;

	///
	///\fn	SceneMan::SceneMan()
	///
	///\brief	Default constructor. Empty (singleton)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	SceneMan(){ };

	///
	///\fn	SceneMan::SceneMan(const SceneMan&)
	///
	///\brief	Copy constructor. Empty (singleton)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	SceneMan(const SceneMan&){ };

	///
	///\fn	SceneMan& SceneMan::operator= (const SceneMan&)
	///
	///\brief	Assignment operator. Empty (singleton)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	SceneMan& operator= (const SceneMan&){ };

	///
	///\fn	SceneMan::~SceneMan()
	///
	///\brief	Destructor. Empty (singleton)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	~SceneMan(){ };

	///
	///\fn	static SceneMan& SceneMan::Instance()
	///
	///\brief	Instance accessor for singleton. If SceneMan hasn't been created yet, create it. Otherwise, return pointer to self. Accessor for all public static methods.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\return	A SceneMan&amp;
	///
	static SceneMan& Instance()
	{
		if (!self)
			self= new SceneMan();
		return *self;
	};

	///\brief	List of scenes.
	std::list<Scene*> sceneList;

	///\brief	The current scene.
	Scene* curScene;

	///\brief	The next scene.
	Scene* nextScene;
	
public:

	///
	///\fn	static void SceneMan::Initialize();
	///
	///\brief	Does initialization tasks.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void Initialize();

	///
	///\fn	static void SceneMan::SetCurScene(Scene* scene);
	///
	///\brief	Sets current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	scene	If non-null, the scene.
	///
	static void SetCurScene(Scene* scene);

	///
	///\fn	static void SceneMan::NextScene(Scene *next);
	///
	///\brief	Sets the next scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	next	If non-null, the next.
	///
	static void NextScene(Scene *next);

	///
	///\fn	static void SceneMan::SetDefaultScene();
	///
	///\brief	Sets default scene (LEGACY FUNCTION, MAY BE REMOVED IN FUTURE VERSIONS). 
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void SetDefaultScene();

	///
	///\fn	static void SceneMan::CheckScene();
	///
	///\brief	Check scene. If current scene is not equal to next scene, begin the scene change process.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void CheckScene();

	///
	///\fn	static void SceneMan::UpdateCurAlarmables();
	///
	///\brief	Updates the current scene's alarmables via its AlarmableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void UpdateCurAlarmables();

	///
	///\fn	static void SceneMan::UpdateCurInputables();
	///
	///\brief	Updates the current scene's inputables via its InputableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void UpdateCurInputables();

	///
	///\fn	static void SceneMan::UpdateCurDrawables();
	///
	///\brief	Updates the current scene's drawables via its DrawableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void UpdateCurDrawables();

	///
	///\fn	static void SceneMan::UpdateCurUpdateables();
	///
	///\brief	Updates the current scene's updateables via its UpdateableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void UpdateCurUpdateables();

	///
	///\fn	static void SceneMan::UpdateCurCollidables();
	///
	///\brief	Updates the current collidables via its CollidableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void UpdateCurCollidables();

	///
	///\fn	static void SceneMan::AlarmRegistration(Alarmable *obj, int alarmID, float time);
	///
	///\brief	Accessor for alarm registration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	alarmID	   	Identifier for the alarm.
	///\param	time	   	The time.
	///
	static void AlarmRegistration(Alarmable *obj, int alarmID, float time);

	///
	///\fn	static void SceneMan::DrawRegistration(Drawable *obj);
	///
	///\brief	Accessor for draw registration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	static void DrawRegistration(Drawable *obj);

	///
	///\fn	static void SceneMan::InputPressRegistration(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Accessor for key press registration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	static void InputPressRegistration(Inputable *obj, AZUL_KEY key);

	///
	///\fn	static void SceneMan::InputReleaseRegistration(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Accessor for key release registration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	static void InputReleaseRegistration(Inputable *obj, AZUL_KEY key);

	///
	///\fn	static void SceneMan::UpdateRegistration(Updateable *obj);
	///
	///\brief	Accessor for update registration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	static void UpdateRegistration(Updateable *obj);

	///
	///\fn	static void SceneMan::AlarmDeregistration(Alarmable *obj, float time);
	///
	///\brief	Accessor for alarm deregistration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	time	   	The time.
	///
	static void AlarmDeregistration(Alarmable *obj, float time);

	///
	///\fn	static void SceneMan::AddAlarmTime(Alarmable *obj, float time);
	///
	///\brief	Accessor for adding time from an alarm which has a callback to obj and has matching time.
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	time	   	The time.
	///\param   timeAdded   The time added.
	///
	static void AddAlarmTime(Alarmable *obj, float time, float timeAdded);

	///
	///\fn	static void SceneMan::SubtractAlarmTime(Alarmable *obj, float time);
	///
	///\brief	Accessor for subtracting time from an alarm which has a callback to obj and has matching time.
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	time	   	The time.
	///\param   timeSubtracted The time subtracted.
	///
	static void SubtractAlarmTime(Alarmable *obj, float time, float timeSubtracted);

	///
	///\fn	static void SceneMan::DrawDeregistration(Drawable *obj);
	///
	///\brief	Accessor for draw deregistration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	static void DrawDeregistration(Drawable *obj);

	///
	///\fn	static void SceneMan::InputPressDeregistration(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Accessor for key press deregistration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	static void InputPressDeregistration(Inputable *obj, AZUL_KEY key);

	///
	///\fn	static void SceneMan::InputReleaseDeregistration(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Accessor for key release deregistration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	static void InputReleaseDeregistration(Inputable *obj, AZUL_KEY key);

	///
	///\fn	static void SceneMan::UpdateDeregistration(Updateable *obj);
	///
	///\brief	Accessor for update deregistration in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	static void UpdateDeregistration(Updateable *obj);

	///
	///\fn	static void SceneMan::MarkForDestroy(Terminable *obj);
	///
	///\brief	Accessor to mark an object for destroy in the current scene via its TerminationMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	static void MarkForDestroy(Terminable *obj);

	///
	///\fn	static void SceneMan::DestroyMarked();
	///
	///\brief	Destroys all marked objects in current scene's TerminationMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void DestroyMarked();

	///
	///\fn	static void SceneMan::DumpsterRegistration(Terminable *obj);
	///
	///\brief	Registers active Terminable in current scene's Dumpster.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	static void DumpsterRegistration(Terminable *obj);

	///
	///\fn	static void SceneMan::DumpsterDeregistration(Terminable *obj);
	///
	///\brief	Deregisters Terminable (either inactive or otherwise managed, e.g. user-created factory) from current scene's Dumpster.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	static void DumpsterDeregistration(Terminable *obj);

	///
	///\fn	static void SceneMan::EmptyDumpster();
	///
	///\brief	Empty current scene's dumpster.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void EmptyDumpster();

	///
	///\fn	static Scene* SceneMan::GetScene()
	///
	///\brief	Returns the current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\return	null if it fails, else the scene.
	///
	static Scene* GetScene()
	{
		return Instance().curScene;
	}

	///
	///\fn	static void SceneMan::InitializeCurScene();
	///
	///\brief	Accessor for user-created InitializeScene method in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void InitializeCurScene();

	///
	///\fn	static void SceneMan::LoadContentCurScene();
	///
	///\brief	Accessor for user-created LoadContentScene method in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void LoadContentCurScene();

	///
	///\fn	static void SceneMan::UpdateCurScene();
	///
	///\brief	Accessor for user-created UpdateScene method in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void UpdateCurScene();

	///
	///\fn	static void SceneMan::DrawCurScene();
	///
	///\brief	Accessor for user-created DrawScene method in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void DrawCurScene();

	///
	///\fn	static void SceneMan::UnLoadCurContentScene();
	///
	///\brief	Accessor for user-created UnloadContentScene method in current scene.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void UnLoadCurContentScene();

	///
	///\fn	static void SceneMan::UnloadAll();
	///
	///\brief	Unloads all scenes. Run at shutdown.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void UnloadAll();

	///
	///\fn	static Dumpster* SceneMan::ReturnSceneDumpster();
	///
	///\brief	Returns current scene dumpster.
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	///\return	null if it fails, else the scene dumpster.
	///
	static Dumpster* ReturnSceneDumpster();
};

#endif

