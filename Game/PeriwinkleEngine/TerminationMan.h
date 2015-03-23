#ifndef _TerminationMan
#define _TerminationMan

#include "Azul.h"
#include <string>
#include <list>
#include <iostream>

class Terminable;

///
///\class	TerminationMan
///\ingroup Managers
///\brief	Per-scene manager for the destruction of all Terminables in the scene, as well as their marking for destruction (actual destruction is performed at the beginning of Update phase to prevent interdependencies/memory access violations).
///
///\author	Max Krieger
///\date	3/5/2015
///
class TerminationMan
{
private:


	///\brief	List of terminables.
	std::list<Terminable*> TerminableList;
public:

	///
	///\fn	TerminationMan::~TerminationMan();
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	~TerminationMan();

	///
	///\fn	void TerminationMan::UpdateAll();
	///
	///\brief	Destroys all terminables that are marked for destroy and calls their OnDestroy method.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void UpdateAll();

	///
	///\fn	void TerminationMan::MarkForDestroy(Terminable *obj);
	///
	///\brief	Mark the input obj for destroy.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void MarkForDestroy(Terminable *obj);
};

#endif