#ifndef _Drawable
#define _Drawable

#include "Azul.h"

///
///\class	Drawable
///\ingroup Draw
///\brief	Base class for all drawable objects.
///
///\author	Max Krieger
///\date	3/4/2015
///
class Drawable
{
public:

	///
	///\fn	virtual Drawable::~Drawable()
	///
	///\brief	Virtual destructor (empty virtual, to be overridden by object)
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual ~Drawable(){};

	///
	///\fn	virtual void Drawable::Draw();
	///
	///\brief	Draw event for this object (empty virtual, to be overridden by object).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void Draw();
};

#endif 