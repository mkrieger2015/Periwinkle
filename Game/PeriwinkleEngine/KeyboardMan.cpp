#include "KeyObject.h"
#include "KeyboardMan.h"

KeyboardMan* KeyboardMan::self = NULL;

void KeyboardMan::CheckKeyStatus()
{
	std::list<KeyObject*>::iterator it;
	it = Instance().KeyList.begin();
	while (it != Instance().KeyList.end())
	{
		(*it)->CheckStatus();
		it++;
	}
}

void KeyboardMan::DebugKeyRegistration(AZUL_KEY key)
{
	bool checked;
	checked= false;
	std::list<KeyObject*>::iterator it;
	it = Instance().KeyList.begin();
	AZUL_KEY temp;
	while (it != Instance().KeyList.end() && checked == false)
	{
		temp= (*it)->ReturnKeyVal();
		if(temp == key)
		{
			checked= true; 
			std::cout << "Key already registered (DEBUG)" << std::endl;
		}
		it++;
	}
	if (checked == false)
	{
		KeyObject* addMe= new KeyObject(key);
		Instance().KeyList.push_front(addMe);
	}
}

void KeyboardMan::DebugKeyDeregistration(AZUL_KEY key)
{
	bool checked;
	checked= false;
	std::list<KeyObject*>::iterator it;
	it = Instance().KeyList.begin();
	AZUL_KEY temp;
	while (it != Instance().KeyList.end() && checked == false)
	{
		temp= (*it)->ReturnKeyVal();
		if(temp == key)
		{
			checked= true; 
			Instance().KeyList.erase(it);
		}
		it++;
	}
	if (checked == false)
	{
		std::cout << "Key not registered! (DEBUG)" << std::endl;
	}
}