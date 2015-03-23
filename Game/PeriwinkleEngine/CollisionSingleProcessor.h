#ifndef _CollisionSingleProcessor
#define _CollisionSingleProcessor

#include "CollisionProcessorBase.h"
#include "CollidableGroup.h"

///
///\class	CollisionSingleProcessor
///\ingroup Collisions
///\brief	This is the CollisionProcessorBase child used for testing collisions against the same class of objects, versus two diffeent objects.
///
///\author	Max Krieger
///\date	3/14/2015
///
///\tparam	C	Type of the c.
///
template <class C>
class CollisionSingleProcessor : public CollisionProcessorBase
{
private:

	///\brief	The collision group used in this processor's collision testing.
	CollidableGroup<C>* colgroup;

public:

	///
	///\fn	CollisionSingleProcessor::CollisionSingleProcessor()
	///
	///\brief	Default constructor. 
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	CollisionSingleProcessor()
	{
		colgroup1 = &CollidableGroup<C>::Instance();
	}

	///
	///\fn	void CollisionSingleProcessor::CollisionTest()
	///
	///\brief	Double dispatch collision test against two objects of the same type.
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	void CollisionTest()
	{
	for(CollidableGroup<C>::CollidableCollection::iterator it_mine = Instance().CollideCol.begin(); it_mine != Instance().CollideCol.end(); it_mine++)
		{
			for(CollidableGroup<C>::CollidableCollection::iterator it_other = next(it_mine); it_other != Instance().CollideCol.end(); it_other++)
			{
				if(Collidable::TestCollisionPair(*it_mine, *it_other))
				{
					(*it_mine)->Collision(*it_other);
					(*it_other)->Collision(*it_mine);
				}
			}
		}
	}
};

#endif