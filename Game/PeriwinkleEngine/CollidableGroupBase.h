#ifndef _CollidableGroupBase
#define _CollidableGroupBase

#include "Azul.h"

///
///\class	CollidableGroupBase
///\ingroup Collisions
///\brief	The base class for the CollidableGroup template class. 
///
///\author	Max Krieger
///\date	3/4/2015
///
class CollidableGroupBase
{
public:

	///
	///\fn	CollidableGroupBase::CollidableGroupBase()
	///
	///\brief	Default constructor (empty).
	///
	///\author	Max Krieger
	///\date	3/12/2015
	///
	CollidableGroupBase(){ };

	///
	///\fn	virtual CollidableGroupBase::~CollidableGroupBase()
	///
	///\brief	Destructor (virtual, empty).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual ~CollidableGroupBase(){ };
};

#endif