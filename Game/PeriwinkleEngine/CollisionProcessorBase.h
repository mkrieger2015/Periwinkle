#ifndef _CollisionProcessorBase
#define _CollisionProcessorBase

///
///\class	CollisionProcessorBase
///\ingroup Collisions
///\brief	The base class for collision processing. Has two children - CollisionPairProcessor, used for testing collisions between two different types, and CollisionSelfProcessor, used for testing collisions between two objects of the same type. 
///
///\author	Max Krieger
///\date	3/14/2015
///
class CollisionProcessorBase
{
public:

	///
	///\fn	CollisionProcessorBase::CollisionProcessorBase()
	///
	///\brief	Default constructor (empty).
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	CollisionProcessorBase(){};

	///
	///\fn	virtual CollisionProcessorBase::~CollisionProcessorBase()
	///
	///\brief	Destructor (virtual, empty).
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	virtual ~CollisionProcessorBase(){};

	///
	///\fn	virtual void CollisionProcessorBase::CollisionTest() = 0;
	///
	///\brief	Collision test function (pure virtual). 
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	virtual void CollisionTest() = 0;
};

#endif