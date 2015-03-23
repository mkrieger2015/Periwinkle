#ifndef _CollidableGroup
#define _CollidableGroup

#include "Azul.h"
#include "CollidableGroupBase.h"
#include <set>
#include <iostream>

///
///\class	CollidableGroup
///\ingroup Collisions
///\brief	The template class for all CollidableGroups. This is a SINGLETON class. Inherits virtual method CallAllTestFunctions from CollidableGroupBase.
///
///\author	Max Krieger
///\date	3/4/2015
///
///\tparam	C	Object type of this CollidableGroup.
///
template <class C>
class CollidableGroup : public CollidableGroupBase
{
	///
	///\brief	CollisionManager is a friend class so it is able to access the CallAllTestFunctions method.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	friend class CollisionManager;
private:

	///
	///\fn	CollidableGroup::CollidableGroup<C>()
	///
	///\brief	Default constructor - unused (singleton).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///
	CollidableGroup<C>(){};

	///
	///\fn	CollidableGroup::CollidableGroup<C>(const CollidableGroup<C>& )
	///
	///\brief	Copy constructor - unused (singleton).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	CollidableGroup<C>(const CollidableGroup<C>& ) {};

	///
	///\fn	CollidableGroup<C> CollidableGroup::operator=(const CollidableGroup<C>&)
	///
	///\brief	Assignment operator for shallow copy - unused (singleton).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	CollidableGroup<C> operator=(const CollidableGroup<C>&){};

public:

	///
	///\typedef	std::set<C*> CollidableCollection
	///
	///\brief	Defines an alias representing collection of collidables.
	///
	typedef std::set<C*> CollidableCollection;


	///\brief	Pointer to self to be used in singleton instance.
	static CollidableGroup<C>* self;

	///
	///\fn	static CollidableGroup<C>& CollidableGroup::Instance()
	///
	///\brief	Creates this CollidableGroup if it does not exist, or returns self if it does. The accessor for ALL methods (singleton). 
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\return	Pointer to this collidable group.
	///
	static CollidableGroup<C>& Instance()
	{
		if (!self)
		{
			self= new CollidableGroup<C>;
		}
		return *self;
	}


	///\brief	Set of objects of type C (template).
	CollidableCollection CollideCol;


	///
	///\fn	static void CollidableGroup::Register(C *p)
	///
	///\brief	Registers the input object to the collision group.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	p	If non-null, the C * to process.
	///
	static void Register(C *p)
	{
		bool found= false;
		typename std::set<C*>::iterator it= Instance().CollideCol.begin();
		while(it != Instance().CollideCol.end() && found == false)
		{
			if((*it) == p)
			{
				found= true;
			}
			it++;
		}
		if(found == false)
			Instance().CollideCol.insert(p);
	}

	///
	///\fn	static void CollidableGroup::Deregister(C *p)
	///
	///\brief	Deregisters the input object from the collision group.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	p	If non-null, the C * to process.
	///
	static void Deregister(C *p)
	{
		bool found= false;
		typename std::set<C*>::iterator it= Instance().CollideCol.begin();
		while(it != Instance().CollideCol.end() && found == false)
		{
			if((*it) == p)
			{
				found= true;
				Instance().CollideCol.erase(it++);
			}
			else
				it++;
		}
	}
	
	///
	///\fn	CollidableGroup::~CollidableGroup<C>()
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\tparam	C	Type of the c.
	///
	~CollidableGroup<C>()
	{
		self= NULL;
	}

};

template <class C>
CollidableGroup<C>* CollidableGroup<C>::self = NULL;

#endif