#ifndef _Inputable
#define _Inputable

#include "Azul.h"

///
///\class	Inputable
///\ingroup Input
///\brief	Base class for all objects that can detect key presses and releases.
///
///\author	Max Krieger
///\date	3/4/2015
///
class Inputable
{

public:

	///
	///\fn	virtual Inputable::~Inputable()
	///
	///\brief	Destructor (empty virtual, to be overridden by object)
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual ~Inputable(){};

	///
	///\fn	virtual void Inputable::RegisterKeyPress(AZUL_KEY key);
	///
	///\brief	Registers this object to the InputManager for a key press event on key key (empty virtual, to be overridden by object)
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void RegisterKeyPress(AZUL_KEY key);

	///
	///\fn	virtual void Inputable::DeregisterKeyPress(AZUL_KEY key);
	///
	///\brief	Deregisters this object to the InputManager from a key press event on key key (empty virtual, to be overridden by object)
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void DeregisterKeyPress(AZUL_KEY key);

	///
	///\fn	virtual void Inputable::RegisterKeyRelease(AZUL_KEY key);
	///
	///\brief	Registers this object to the InputManager for a key release event on key key (empty virtual, to be overridden by object)
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void RegisterKeyRelease(AZUL_KEY key);

	///
	///\fn	virtual void Inputable::DeregisterKeyRelease(AZUL_KEY key);
	///
	///\brief	Deregisters this object to the InputManager from a key release event on key key (empty virtual, to be overridden by object)
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void DeregisterKeyRelease(AZUL_KEY key);

	///
	///\fn	virtual void Inputable::OnKeyPress(AZUL_KEY key);
	///
	///\brief		Method containing all key press events, which one is to be activated is determined by the key passed in (empty virtual, to be overridden by object)
	///
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void OnKeyPress(AZUL_KEY key);

	///
	///\fn	virtual void Inputable::OnKeyRelease(AZUL_KEY key);
	///
	///\brief	Method containing all key release events, which one is to be activated is determined by the key passed in (empty virtual, to be overridden by object)
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void OnKeyRelease(AZUL_KEY key);
};

#endif 