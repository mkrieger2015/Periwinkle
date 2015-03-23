#ifndef _KeyObject
#define _KeyObject

#include "Azul.h"
#include <iostream>
#include <list>

class Inputable; 

///
///\class	KeyObject
///\ingroup Input
///\brief	An object registered to the InputableMan, which manages all callbacks for its assigned key.
///
///\author	Max Krieger
///\date	3/4/2015
///

class KeyObject
{
private: 

	///\brief	Key state the frame before (up or down)
	bool prevState;

	///\brief	Key state of the current frame (up or down)
	bool curState;

	///\brief	The key value.
	AZUL_KEY keyVal;

	///\brief	List of press callbacks.
	std::list<Inputable*> pressList;

	///\brief	List of release callbacks.
	std::list<Inputable*> releaseList;
public:

	///
	///\fn	KeyObject::KeyObject();
	///
	///\brief	Default constructor (NOT TO BE USED).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	KeyObject();

	///
	///\fn	KeyObject::~KeyObject();
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	~KeyObject();

	///
	///\fn	KeyObject::KeyObject(AZUL_KEY keyReg);
	///
	///\brief	Constructor, with keyReg representing this object's assigned key.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	keyReg	The key register.
	///
	KeyObject(AZUL_KEY keyReg);

	///
	///\fn	void KeyObject::RegisterPress(Inputable *obj);
	///
	///\brief	Registers obj for a press callback.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void RegisterPress(Inputable *obj);

	///
	///\fn	void KeyObject::RegisterRelease(Inputable *obj);
	///
	///\brief	Registers obj for a release callback.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void RegisterRelease(Inputable *obj);

	///
	///\fn	void KeyObject::DeregisterPress(Inputable *obj);
	///
	///\brief	Deregisters obj from a press callback.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void DeregisterPress(Inputable *obj);

	///
	///\fn	void KeyObject::DeregisterRelease(Inputable *obj);
	///
	///\brief	Deregisters obj from a release callback.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void DeregisterRelease(Inputable *obj);

	///
	///\fn	void KeyObject::CheckStatus();
	///
	///\brief	Called per-frame by InputableMan. Check status of key this frame compared to key last frame to determine if pressed/released, and trigger relevant callbacks.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void CheckStatus(); 

	///
	///\fn	AZUL_KEY KeyObject::ReturnKeyVal();
	///
	///\brief	Public key value accessor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\return	The key value.
	///
	AZUL_KEY ReturnKeyVal();
};

#endif