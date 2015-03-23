#ifndef _CollisionPairProcessor
#define _CollisionPairProcessor

#include "CollisionProcessorBase.h"
#include "CollidableGroup.h"

///
///\class	CollisionPairProcessor
///\ingroup Collisions
///\brief	A collision processor for two objects of DIFFERENT types. If you wish to test collisions between two objects of the same type, use CollisionSingleProcessor.
///
///\author	Max Krieger
///\date	3/14/2015
///
///\tparam	C1	Type of the c 1.
///\tparam	C2	Type of the c 2.
///
template <class C1, class C2>
class CollisionPairProcessor : public CollisionProcessorBase
{

private:

	///\brief	The CollidableGroup of the first object type.
	CollidableGroup<C1>* colgroup1;

	///\brief	The CollidableGroup of the second object type.
	CollidableGroup<C2>* colgroup2;

public:

	///
	///\fn	CollisionPairProcessor::CollisionPairProcessor()
	///
	///\brief	Default constructor.
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	CollisionPairProcessor()
	{
		colgroup1 = &CollidableGroup<C1>::Instance();
		colgroup2 = &CollidableGroup<C2>::Instance();
	}

	///
	///\fn	void CollisionPairProcessor::CollisionTest()
	///
	///\brief	Double dispatch collision test against two objects of different types.
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	void CollisionTest()
	{
		bool test_result;
		CollidableGroup<C1>::CollidableCollection::iterator it_mine;
		CollidableGroup<C2>::CollidableCollection::iterator it_other;
		it_mine= CollidableGroup<C1>::Instance().CollideCol.begin();
		it_other= CollidableGroup<C2>::Instance().CollideCol.begin();
		while(it_mine != CollidableGroup<C1>::Instance().CollideCol.end())
		{
			while(it_other != CollidableGroup<C2>::Instance().CollideCol.end())
			{
				test_result = Collidable::TestCollisionPair(*it_mine, *it_other);
			
				if(test_result == true)
				{
					(*it_mine)->Collision(*it_other);
					(*it_other)->Collision(*it_mine);
				}
				it_other++;
			}
			it_mine++;
		}
	}
};

#endif