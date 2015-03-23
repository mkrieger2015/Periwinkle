#ifndef _KeyboardMan
#define _KeyboardMan

#include <list>
#include <iostream>
#include "Azul.h"
#include "InputMan.h"

class KeyObject;

///
///\class	KeyboardMan
///
///\brief	OBSOLETE LEGACY CLASS MARKED FOR REMOVAL. DO NOT USE.
///
///\author	Max Krieger
///\date	3/4/2015
///
class KeyboardMan
{
private: 
	static KeyboardMan *self;

	KeyboardMan(){ };
	KeyboardMan(const KeyboardMan&){ };
	KeyboardMan& operator= (const KeyboardMan&){ };

	~KeyboardMan(){ };
	
	static KeyboardMan& Instance()
	{
		if (!self)
			self= new KeyboardMan();
		return *self;
	};

	std::list<KeyObject*> KeyList;

public: 
	static void CheckKeyStatus();
	//static void RegisterKey(AZUL_KEY key); //to be expanded upon when GameObjects are finalized
	//static void DeregisterKey(AZUL_KEY key); //to be expanded upon when GameObjects are finalized
	static void DebugKeyRegistration(AZUL_KEY key); //this function will only serve to test the manager and key objects, will be removed when the above two functions are implemented
	static void DebugKeyDeregistration(AZUL_KEY key);  //this function will only serve to test the manager and key objects, will be removed when the above two functions are implemented
};

#endif 