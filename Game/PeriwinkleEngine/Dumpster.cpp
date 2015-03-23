#include "Dumpster.h"
#include <iostream>
#include "TerminableReciever.h"
#include "Terminable.h"

void Dumpster::Register(Terminable* obj)
{
	bool found;
	found= false;
	std::list<Terminable*>::iterator it;
	it = DumpsterList.begin();
	while(it != DumpsterList.end() && found == false)
	{
		if((*it) == obj)
		{
			found= true; 
			std::cout << "Object already in the dump" << std::endl;
		}
		it++;
	}
	if (found == false)
	{
		DumpsterList.push_front(obj);
		obj->SetTerminableReciever();
	}
}

void Dumpster::Deregister(Terminable* obj)
{
	bool found;
	found= false;
	std::list<Terminable*>::iterator it;
	it = DumpsterList.begin();
	while(it != DumpsterList.end() && found == false)
	{
		if((*it) == obj)
		{
			found= true; 
			DumpsterList.erase(it++);
		}
		else
			it++;
	}
	if (found == false)
	{
		std::cout << "This object is not in the dump" << std::endl;
	}
}

void Dumpster::DeleteAll()
{
	std::list<Terminable*>::iterator it;
	Terminable* temp;
	it = DumpsterList.begin();
	while(it != DumpsterList.end())
	{
		temp= (*it);
		DumpsterList.erase(it++);
		delete temp;
	}
}

void Dumpster::RecieveAction(Terminable *t)
{
	Deregister(t);
	t->OnDestroy();
	delete t;
}