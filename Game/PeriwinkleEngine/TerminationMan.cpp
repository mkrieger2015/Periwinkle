#include "TerminationMan.h"
#include "TerminableReciever.h"
#include "Terminable.h"
#include "SceneMan.h"

void TerminationMan::MarkForDestroy(Terminable *obj)
{
	bool found;
	found= false;
	std::list<Terminable*>::iterator it;
	it = TerminableList.begin();
	Terminable *temp;
	while (it != TerminableList.end() && found == false)
	{
		temp= (*it);
		if(temp == obj)
		{
			found= true; 
			std::cout << "Object already marked for destroy" << std::endl;
		}
		it++;
	}
	if (found == false)
	{
		TerminableList.push_front(obj);
	}
}

void TerminationMan::UpdateAll()
{
	std::list<Terminable*>::iterator it;
	it = TerminableList.begin();
	while (it != TerminableList.end())
	{
		(*it)->DeregisterAll();
		(*it)->GetTerminableReciever()->RecieveAction(*it);
		Terminable *temp;
		temp= (*it);
		TerminableList.erase(it++);
	}
}

TerminationMan::~TerminationMan()
{
	//std::cout << "Look, mah, I have a destructor!" << std::endl;
}