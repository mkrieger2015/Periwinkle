#ifndef _InputableMan
#define _InputableMan

#include "Azul.h"
#include <string>
#include <list>

class Inputable;
class KeyObject;

///
///\class	InputableMan
///\ingroup Managers
///\brief	Per-scene manager for all KeyObjects, to manage per-frame key presses and key releases.
///
///\author	Max Krieger
///\date	3/4/2015
///

class InputableMan
{
private:


	///\brief	List of KeyObjects.
	std::list<KeyObject*> KeyList;
public:

	///
	///\fn	InputableMan::~InputableMan();
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	~InputableMan();

	///
	///\fn	void InputableMan::RegisterKeyPress(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Registers obj for a key press on KeyObject key. If such a KeyObject doesn't exist yet, create one.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	void RegisterKeyPress(Inputable *obj, AZUL_KEY key);

	///
	///\fn	void InputableMan::DeregisterKeyPress(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Deregisters obj from a key press on KeyObject key.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	void DeregisterKeyPress(Inputable *obj, AZUL_KEY key);

	///
	///\fn	void InputableMan::RegisterKeyRelease(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Registers obj for a key release on KeyObject key. If such a KeyObject doesn't exist yet, create one.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	void RegisterKeyRelease(Inputable *obj, AZUL_KEY key);

	///
	///\fn	void InputableMan::DeregisterKeyRelease(Inputable *obj, AZUL_KEY key);
	///
	///\brief	Deregisters obj from a key release on KeyObject key.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	key		   	The key.
	///
	void DeregisterKeyRelease(Inputable *obj, AZUL_KEY key);

	///
	///\fn	void InputableMan::CheckKeyStatus();
	///
	///\brief	Per-frame check on all KeyObjects to see if they have been pressed or released, and triggering relevant callbacks.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void CheckKeyStatus();

};

#endif

