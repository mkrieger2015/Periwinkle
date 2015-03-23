#ifndef _Scene
#define _Scene

#include "Azul.h"
#include <string>
 
class InputableMan;
class DrawableMan;
class UpdateableMan;
class CollisionMan;
class TerminationMan;
class AlarmMan;
class Updateable;
class Inputable;
class Drawable;
class Alarmable;
class Collidable;
class Terminable;
class Dumpster;

///
///\class	Scene
///\ingroup Scene
///\brief	The base scene class. 
///
///\author	Max Krieger
///\date	3/5/2015
///

class Scene
{
protected:

	///\brief	This scene's AlarmMan.
	AlarmMan* am;

	///\brief	This scene's InputableMan.
	InputableMan* im;

	///\brief	This scene's DrawableMan.
	DrawableMan* dm;

	///\brief	This scene's UpdateableMan.
	UpdateableMan* um;

	///\brief	This scene's CollisionMan.
	CollisionMan* cm;

	///\brief	This scene's TerminationMan.
	TerminationMan* tm;

	///\brief	This scene's Dumpster.
	Dumpster *dmp;
	
public:

	///
	///\fn	Scene::Scene();
	///
	///\brief	Constructor.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	Scene();

	///
	///\fn	virtual Scene::~Scene();
	///
	///\brief	Destructor. Virtual, can be overwritten by user, but has a default.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual ~Scene();

	///
	///\fn	void Scene::UpdateInputableMan();
	///
	///\brief	Updates the InputableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void UpdateInputableMan();

	///
	///\fn	void Scene::UpdateDrawableMan();
	///
	///\brief	Updates the DrawableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void UpdateDrawableMan();

	///
	///\fn	void Scene::UpdateUpdateableMan();
	///
	///\brief	Updates the UpdateableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void UpdateUpdateableMan();

	///
	///\fn	void Scene::UpdateAlarmMan();
	///
	///\brief	Updates the AlarmMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void UpdateAlarmMan();

	///
	///\fn	void Scene::UpdateCollisionMan();
	///
	///\brief	Updates the CollisionMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void UpdateCollisionMan();

	///
	///\fn	void Scene::UpdateTerminationMan();
	///
	///\brief	Updates the TerminationMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void UpdateTerminationMan();

	///
	///\fn	void Scene::DrawRegistration(Drawable *obj);
	///
	///\brief	Accessor for Drawable registration to DrawableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void DrawRegistration(Drawable *obj);

	///
	///\fn	void Scene::InputPressRegistration(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Accessor for key press registration to InputableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	void InputPressRegistration(Inputable *obj, AZUL_KEY key);

	///
	///\fn	void Scene::InputReleaseRegistration(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Accessor for key release registration to InputableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	void InputReleaseRegistration(Inputable *obj, AZUL_KEY key);

	///
	///\fn	void Scene::UpdateRegistration(Updateable *obj);
	///
	///\brief	Accessor for update registration to UpdateableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void UpdateRegistration(Updateable *obj);

	///
	///\fn	void Scene::DrawDeregistration(Drawable *obj);
	///
	///\brief	Accessor for draw registration to DrawableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void DrawDeregistration(Drawable *obj);

	///
	///\fn	void Scene::InputPressDeregistration(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Accessor for key press deregistration from InputableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	void InputPressDeregistration(Inputable *obj, AZUL_KEY key);

	///
	///\fn	void Scene::InputReleaseDeregistration(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Accessor for key release deregistration from InputableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	void InputReleaseDeregistration(Inputable *obj, AZUL_KEY key);

	///
	///\fn	void Scene::UpdateDeregistration(Updateable *obj);
	///
	///\brief	Accessor for update deregistration from UpdateableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void UpdateDeregistration(Updateable *obj);

	///
	///\fn	void Scene::AlarmRegistration(Alarmable *obj, int alarmID, float time);
	///
	///\brief	Accessor for alarm registration to AlarmableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	alarmID	   	Identifier for the alarm.
	///\param	time	   	The time.
	///
	void AlarmRegistration(Alarmable *obj, int alarmID, float time);

	///
	///\fn	void Scene::AlarmDeregistration(Alarmable *obj, float time);
	///
	///\brief	Accessor for alarm deregistration from AlarmableMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	time	   	The time.
	///
	void AlarmDeregistration(Alarmable *obj, float time);

	///
	///\fn	void Scene::AddAlarmTime(Alarmable *obj, float time, float timeAdded);
	///
	///\brief	Adds time to an alarm with callback to obj and matching time.
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	time	   	The time.
	///\param	timeAdded  	The time added.
	///
	void AddAlarmTime(Alarmable *obj, float time, float timeAdded);

	///
	///\fn	void Scene::SubtractAlarmTime(Alarmable *obj, float, float timeSubtracted);
	///
	///\brief	Subtracts time from an alarm with a callback to obj and matching time. 
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	///\param [in,out]	obj   	If non-null, the object.
	///\param	time            The time.
	///\param	timeSubtracted	The time subtracted.
	///
	void SubtractAlarmTime(Alarmable *obj, float time, float timeSubtracted);

	///
	///\fn	void Scene::MarkForDestroy(Terminable *obj);
	///
	///\brief	Accessor to register an object for destroy in TerminationMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void MarkForDestroy(Terminable *obj);

	///
	///\fn	void Scene::DestroyMarked();
	///
	///\brief	Tells TerminationMan to destroy those marked for destroy.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void DestroyMarked();

	///
	///\fn	void Scene::DumpsterRegistration(Terminable *obj);
	///
	///\brief	Registers an active Terminable in the Dumpster.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void DumpsterRegistration(Terminable *obj);

	///
	///\fn	void Scene::DumpsterDeregistration(Terminable *obj);
	///
	///\brief	Deregisters a Terminable (either inactive or otherwise managed, e.g. by a user-created factory) from the Dumpster.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void DumpsterDeregistration(Terminable *obj);

	///
	///\fn	void Scene::EmptyDumpster();
	///
	///\brief	Empty dumpster.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void EmptyDumpster();

	///
	///\fn	void Scene::Cleanup();
	///
	///\brief	Cleanups this object (EMPTY FOR NOW, to be expanded).
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void Cleanup();

	//this is a debug function for the set collision pair passthrough to work
	//I couldn't figure out how to create a template function accessor
	//so I'm having to directly access the current scene 

	CollisionMan* getCollisionMan(){return cm;}

	///
	///\fn	virtual void Scene::InitializeScene();
	///
	///\brief	Things for the scene to do upon initialization. User-definable, empty in default case.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual void InitializeScene();

	///
	///\fn	virtual void Scene::LoadContentScene();
	///
	///\brief	Loads scene content. User-definable, empty in default case.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual void LoadContentScene();

	///
	///\fn	virtual void Scene::UpdateScene();
	///
	///\brief	Updates the scene. User-definable, empty in default case.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual void UpdateScene();

	///
	///\fn	virtual void Scene::DrawScene();
	///
	///\brief	Draw scene contents. User-definable, empty in default case.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual void DrawScene();

	///
	///\fn	virtual void Scene::UnLoadContentScene();
	///
	///\brief	Unload scene content. User-definable, empty in default case.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual void UnLoadContentScene();

	///
	///\fn	virtual void Scene::OnSceneEnd();
	///
	///\brief	Final cleanup for scene. User-definable, empty in default case.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual void OnSceneEnd();

	///
	///\fn	virtual Dumpster* Scene::ReturnDumpster();
	///
	///\brief	Returns reference to the dumpster.
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	///\return	null if it fails, else the dumpster.
	///
	virtual Dumpster* ReturnDumpster();

};

#endif

