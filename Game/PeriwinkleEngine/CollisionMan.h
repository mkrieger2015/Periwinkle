#ifndef _CollisionMan
#define _CollisionMan

#include "Azul.h"
#include "CollidableGroup.h"
#include "CollisionPairProcessor.h"
#include "CollisionSingleProcessor.h"
#include <set>
#include <list>

///
///\class	CollisionMan
///\ingroup Managers
///\brief	Per-scene manager for all active Collidables in that scene.
///
///\author	Max Krieger
///\date	3/4/2015
///
class CollisionMan
{
private:

	///\brief	Collection of collision groups.
	std::set<CollidableGroupBase*> CollisionGroupCollection;
	std::list<CollisionProcessorBase*> ProcessorCollection;

public:

	///
	///\fn	template< class C > void CollisionMan::SetCollisionSelf()
	///
	///\brief	Adds the collidable group to the CollisionGroupCollection. Also adds a new CollisionSingleProcessor to the ProcessorCollection to manage the collision processing for this type.
	///
	///\author	Max Krieger
	///\date	3/12/2015
	///
	///\tparam	C	Type of the c.
	///
	template< class C > 
	void SetCollisionSelf()
	{
		CollisionGroupCollection.insert(&CollidableGroup<C>::Instance());
		ProcessorCollection.push_front(new CollisionSingleProcessor<C>());
	}

	///
	///\fn	template <class C1, class C2> void CollisionMan::SetCollisionPair()
	///
	///\brief	Adds both collidable groups to the CollisionGroupCollection. Also adds a new CollisionPairProcessor to the ProcessorCollection to manage the collision processing for these two types.
	///
	///\author	Max Krieger
	///\date	3/12/2015
	///
	///\tparam	C1	Type of the first CollidableGroup.
	///\tparam	C2	Type of the second CollidableGroup.
	///
	template< class C1, class C2 >
	void SetCollisionPair()
	{
		CollisionGroupCollection.insert( &CollidableGroup<C1>::Instance());
		CollisionGroupCollection.insert( &CollidableGroup<C2>::Instance());
		ProcessorCollection.push_front(new CollisionPairProcessor<C1,C2>());
	}

	///
	///\fn	void CollisionMan::ProcessCollisions();
	///
	///\brief	Executes per-frame processing on each collidable group registered to the CollisionGroupCollection.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void ProcessCollisions();

	///
	///\fn	CollisionMan::~CollisionMan();
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	~CollisionMan();
};

#endif