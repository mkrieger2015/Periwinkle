#ifndef _UpdateableMan
#define _UpdateableMan

#include "Azul.h"
#include <string>
#include <list>
#include <iostream>

class Updateable;

///
///\class	UpdateableMan
///\ingroup Managers
///\brief	Per-scene manager for updating Updateables. 
///
///\author	Max Krieger
///\date	3/5/2015
///
class UpdateableMan
{
private:


	///\brief	List of updateables.
	std::list<Updateable*> UpdateableList;
public:

	///
	///\fn	UpdateableMan::~UpdateableMan();
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	~UpdateableMan();

	///
	///\fn	void UpdateableMan::UpdateAll();
	///
	///\brief	Updates all registered Updateables.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void UpdateAll();

	///
	///\fn	void UpdateableMan::Register(Updateable *obj);
	///
	///\brief	Registers an Updateable to the list.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void Register(Updateable *obj);

	///
	///\fn	void UpdateableMan::Deregister(Updateable *obj);
	///
	///\brief	Deregisters an Updateable from the list.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void Deregister(Updateable *obj);
};

#endif