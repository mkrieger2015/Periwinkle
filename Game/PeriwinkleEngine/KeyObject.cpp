#include "KeyObject.h"
#include "Inputable.h"

KeyObject::KeyObject()
{

}

KeyObject::KeyObject(AZUL_KEY keyReg)
{
	prevState= false;
	keyVal= keyReg;
}

void KeyObject::CheckStatus()
{
	curState= InputMan::GetKeyboard()->GetKeyState(keyVal);

	if(curState == true && prevState == false)
	{
		std::list<Inputable*>::iterator it;
		it = pressList.begin();
		while (it != pressList.end())
		{
			(*it)->OnKeyPress(keyVal);
			it++;
		}
	}
	else if (curState == false && prevState == true)
	{
		std::list<Inputable*>::iterator it;
		it = releaseList.begin();
		while (it != releaseList.end())
		{
			(*it)->OnKeyRelease(keyVal);
			it++;
		}
	}

	prevState= curState;
}

void KeyObject::RegisterPress(Inputable *obj)
{
	bool found;
	found= false;
	std::list<Inputable*>::iterator it;
	it = pressList.begin();
	while (it != pressList.end() && found == false)
	{
		if((*it) == obj)
		{
			found= true;
			std::cout << "Attempt to register an already registered press!" << std::endl;
		}
		it++;
	}
	if (found == false)
	{
		pressList.push_front(obj);
	}
}

void KeyObject::RegisterRelease(Inputable *obj)
{
	bool found;
	found= false;
	std::list<Inputable*>::iterator it;
	it = releaseList.begin();
	while (it != releaseList.end() && found == false)
	{
		if((*it) == obj)
		{
			found= true;
			std::cout << "Attempt to register an already registered release!" << std::endl;
		}
		it++;
	}
	if (found == false)
	{
		releaseList.push_front(obj);
	}
}

void KeyObject::DeregisterPress(Inputable *obj)
{
	bool found;
	found= false;
	std::list<Inputable*>::iterator it;
	it = pressList.begin();
	while (it != pressList.end() && found == false)
	{
		if((*it) == obj)
		{
			found= true;
			pressList.erase(it);
		}
		it++;
	}
	if (found == false)
	{
		std::cout << "Attempt to deregister an unregistered press!" << std::endl;
	}
}

void KeyObject::DeregisterRelease(Inputable *obj)
{
	bool found;
	found= false;
	std::list<Inputable*>::iterator it;
	it = releaseList.begin();
	while (it != releaseList.end() && found == false)
	{
		if((*it) == obj)
		{
			found= true;
			releaseList.erase(it);
		}
		it++;
	}
	if (found == false)
	{
		std::cout << "Attempt to deregister an unregistered release!" << std::endl;
	}
}


AZUL_KEY KeyObject::ReturnKeyVal()
{
	return keyVal;
}

KeyObject::~KeyObject()
{
	/*std::list<Inputable*>::iterator it;
	it = pressList.begin();
	while (it != pressList.end())
	{
		(*it)->OnKeyPress(keyVal);
		it++;
	}
	*/
}