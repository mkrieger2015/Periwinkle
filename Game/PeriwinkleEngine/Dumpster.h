#ifndef _Dumpster
#define _Dumpster

#include "Azul.h"
#include "TerminableReciever.h"
#include <list>

class Terminable;

///
///\class	Dumpster
///\ingroup Managers
///\brief	Per-scene "dumpster" to dispose of all Terminable objects when scene is changed or game is shut down. This disposal is distinct from termination in the Terminable's sense!
///
///\author	Max Krieger
///\date	3/4/2015
///
class Dumpster : public TerminableReciever
{
private:

	///\brief	List of active Terminables in the scene.
	std::list<Terminable*> DumpsterList;

public:

	///
	///\fn	void Dumpster::Register(Terminable* obj);
	///
	///\brief	Registers the input object to the dumpster.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void Register(Terminable* obj);

	///
	///\fn	void Dumpster::Deregister(Terminable* obj);
	///
	///\brief	Deregisters the input object from the dumpster.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void Deregister(Terminable* obj);

	///
	///\fn	void Dumpster::DeleteAll();
	///
	///\brief	Disposes (deletes without triggering OnTermination method) of all objects currently in the dumpster.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void DeleteAll();

	///
	///\fn	void Dumpster::RecieveAction(Terminable *t)
	///
	///\brief	Dumpster's derivation of the TerminableReciever's RecieveAction. This simply deletes the 
	///
	///\author	Max Krieger
	///\date	3/11/2015
	///
	///\param [in,out]	t	If non-null, the Terminable * to process.
	///
	void RecieveAction(Terminable *t);

};

#endif