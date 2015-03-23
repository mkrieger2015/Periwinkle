#include "UpdateableMan.h"
#include "Updateable.h"

void UpdateableMan::Register(Updateable *obj)
{
	bool found;
	found= false;
	std::list<Updateable*>::iterator it;
	it = UpdateableList.begin();
	Updateable *temp;
	while (it != UpdateableList.end() && found == false)
	{
		temp= (*it);
		if(temp == obj)
		{
			found= true; 
			std::cout << "Updateable already registered (DEBUG)" << std::endl;
		}
		it++;
	}
	if (found == false)
	{
		UpdateableList.push_front(obj);
	}
}

void UpdateableMan::Deregister(Updateable *obj)
{
	bool found;
	found= false;
	std::list<Updateable*>::iterator it;
	it = UpdateableList.begin();
	Updateable *temp;
	while (it != UpdateableList.end() && found == false)
	{
		temp= (*it);
		if (temp == obj)
		{
			found= true;
			UpdateableList.erase(it++);
		}
		else
			it++;
	}
	if (found == false)
	{
		std::cout << "Attempted dereg of unregistered Updateable (DEBUG)" << std::endl;
	}
}

void UpdateableMan::UpdateAll()
{
	std::list<Updateable*>::iterator it;
	it = UpdateableList.begin();
	while (it != UpdateableList.end())
	{
		(*it)->Update();
		it++;
	}
}

UpdateableMan::~UpdateableMan()
{
	//std::cout << "Look, mah, I have a destructor!" << std::endl;
}