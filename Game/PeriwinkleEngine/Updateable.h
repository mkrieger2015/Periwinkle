#ifndef _Updateable
#define _Updateable

#include "Azul.h"

///
///\class	Updateable
///\ingroup Update
///\brief	Base class for all updateable objects (e.g. something happens during the Update step).
///
///\author	Max Krieger
///\date	3/5/2015
///
class Updateable
{
public:

	///
	///\fn	virtual void Updateable::Update();
	///
	///\brief	Updates this object (empty, virtual - to be defined by user)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual void Update();

	///
	///\fn	virtual Updateable::~Updateable()
	///
	///\brief	Destructor (empty, virtual - to be defined by user)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual ~Updateable(){};
};

#endif 