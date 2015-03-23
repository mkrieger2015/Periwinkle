#ifndef _Collidable
#define _Collidable

#include "Azul.h"

///
///\class	Collidable
///\ingroup   Collisions
///\brief	Parent class for all collision-enabled objects.
///
///\author	Max Krieger
///\date	3/4/2015
///
class Collidable
{
protected:


	///\brief	The graphicsobject used to determine collision bounds.
	GraphicsObject* mainColliderObject;


	///\brief	The main collider center.
	Vect mainColliderCenter;

	///\brief	The main collider radius.
	float mainColliderRadius;
public:

	///
	///\fn	virtual Collidable::~Collidable()
	///
	///\brief	Destructor (empty).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual ~Collidable(){};

	///
	///\fn	virtual void Collidable::Collision(Collidable* col);
	///
	///\brief	Collision event, with a reference to the other object involved in the collision passed in.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	col	If non-null, the col.
	///
	virtual void Collision(Collidable* col);

	///
	///\fn	static bool Collidable::TestCollisionPair(Collidable* c1, Collidable* c2);
	///
	///\brief	Tests collision pair.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	c1	If non-null, the first Collidable.
	///\param [in,out]	c2	If non-null, the second Collidable.
	///
	///\return	true if the test passes, false if the test fails.
	///
	static bool TestCollisionPair(Collidable* c1, Collidable* c2);

	///
	///\fn	template <typename C> void Collidable::RegisterCollision( C *c)
	///
	///\brief	Registers the collision described by c (Currently empty).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\tparam	C	Type of the c.
	///\param [in,out]	c	If non-null, the C * to process.
	///
	template <typename C>
	void RegisterCollision( C *c)
	{

	}

	///
	///\fn	template <typename C> void Collidable::DeregisterCollision( C *c)
	///
	///\brief	Deregisters the collision described by c (currently empty).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\tparam	C	Type of the c.
	///\param [in,out]	c	If non-null, the C * to process.
	///
	template <typename C>
	void DeregisterCollision( C *c)
	{

	}

};

#endif
