#include "CollisionMan.h"
#include "CollidableGroup.h"
#include <iostream>

void CollisionMan::ProcessCollisions()
{
	std::list<CollisionProcessorBase*>::iterator it;
	it= ProcessorCollection.begin();
	while (it != ProcessorCollection.end())
	{
		(*it)->CollisionTest();
		it++;
	}
}

CollisionMan::~CollisionMan()
{
	std::set<CollidableGroupBase*>::iterator it;
	it= CollisionGroupCollection.begin();
	while (it != CollisionGroupCollection.end())
	{
		delete (*it);
		it++;
	}
}