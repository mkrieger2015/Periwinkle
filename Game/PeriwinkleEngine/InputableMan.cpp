#include "InputableMan.h"
#include "Inputable.h"
#include "KeyObject.h"

void InputableMan::CheckKeyStatus()
{
	std::list<KeyObject*>::iterator it;
	it = KeyList.begin();
	while (it != KeyList.end())
	{
		(*it)->CheckStatus();
		it++;
	}
}

void InputableMan::RegisterKeyPress(Inputable *obj, AZUL_KEY key)
{
	bool found;
	found = false;
	AZUL_KEY temp;
	std::list<KeyObject*>::iterator it;
	it = KeyList.begin();

	while (it != KeyList.end() && found == false)
	{
		temp= (*it)->ReturnKeyVal();
		if(temp == key)
		{
			found= true; 
			(*it)->RegisterPress(obj);
		}
		it++;
	}
	if (found == false)
	{
		KeyObject* addMe= new KeyObject(key);
		KeyList.push_front(addMe);
		addMe->RegisterPress(obj);
	}
}

void InputableMan::RegisterKeyRelease(Inputable *obj, AZUL_KEY key)
{
	bool found;
	found = false;
	AZUL_KEY temp;
	std::list<KeyObject*>::iterator it;
	it = KeyList.begin();

	while (it != KeyList.end() && found == false)
	{
		temp= (*it)->ReturnKeyVal();
		if(temp == key)
		{
			found= true; 
			(*it)->RegisterRelease(obj);
		}
		it++;
	}
	if (found == false)
	{
		KeyObject* addMe= new KeyObject(key);
		KeyList.push_front(addMe);
		addMe->RegisterRelease(obj);
	}
}

void InputableMan::DeregisterKeyPress(Inputable *obj, AZUL_KEY key)
{
	bool found;
	found= false;
	std::list<KeyObject*>::iterator it;
	it = KeyList.begin();
	AZUL_KEY temp;
	while (it != KeyList.end() && found == false)
	{
		temp= (*it)->ReturnKeyVal();
		if(temp == key)
		{
			found= true; 
			(*it)->DeregisterPress(obj);
		}
		it++;
	}
	if (found == false)
	{
		std::cout << "Attempted dereg of an unregistered Inputtable! (DEBUG)" << std::endl;
	}
}

void InputableMan::DeregisterKeyRelease(Inputable *obj, AZUL_KEY key)
{
	bool found;
	found= false;
	std::list<KeyObject*>::iterator it;
	it = KeyList.begin();
	AZUL_KEY temp;
	while (it != KeyList.end() && found == false)
	{
		temp= (*it)->ReturnKeyVal();
		if(temp == key)
		{
			found= true; 
			(*it)->DeregisterRelease(obj);
		}
		it++;
	}
	if (found == false)
	{
		std::cout << "Attempted dereg of an unregistered Inputtable! (DEBUG)" << std::endl;
	}
}

InputableMan::~InputableMan()
{
	std::list<KeyObject*>::iterator it;
	it = KeyList.begin();
	while (it != KeyList.end())
	{
		delete (*it);
		it++;
	}
}