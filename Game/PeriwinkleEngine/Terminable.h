#ifndef _Terminable
#define _Terminable

#include "Azul.h"

///
///\class	Terminable
///\ingroup Termination
///\brief	Base class for all terminable objects (both TerminationMan and Dumpster take this type). 
///
///\author	Max Krieger
///\date	3/5/2015
///

class TerminableReciever;

class Terminable
{
protected:

	///\brief	The TerminableReciever assigned to this terminable. Leave this alone to have the object be handled by the Dumpster. If you instead have a factory, make sure to grab its reference via the SceneMan and store it here.
	TerminableReciever *tr;

public:

	///
	///\fn	virtual Terminable::~Terminable()
	///
	///\brief	Destructor (virtual, to be user-defined). DIFFERENT THAN ONDESTROY - this destructor is invoked by the Dumpster, NOT THE TerminationMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual ~Terminable(){};

	///
	///\fn	void Terminable::MarkForDestroy();
	///
	///\brief	Wrapper for marking this object for destroy with the current scene's TerminationMan.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	void MarkForDestroy();

	///
	///\fn	virtual void Terminable::OnDestroy();
	///
	///\brief	Any cleanup or other actions to be performed on destroy. DIFFERENT THAN THE DESTRUCTOR - this method is invoked by the TerminationMan, NOT THE DUMPSTER.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual void OnDestroy();

	///
	///\fn	virtual void Terminable::SetTerminableReciever();
	///
	///\brief	Public accessor to set this Terminable 's TerminableReciever to NULL.
	///
	///\author	Max Krieger
	///\date	3/11/2015
	///
	virtual void SetTerminableReciever();

	///
	///\fn	virtual void Terminable::SetTerminableReciever(TerminableReciever* tr);
	///
	///\brief	Public accessor to set this Terminable 's TerminableReciever to the parameter tr.
	///
	///\author	Max Krieger
	///\date	3/11/2015
	///
	///\param [in,out]	tr	If non-null, the tr.
	///
	virtual void SetTerminableReciever(TerminableReciever* trIn);

	///
	///\fn	virtual TerminableReciever* Terminable::GetTerminableReciever();
	///
	///\brief	Public accessor to access this Terminable's TerminableReciever. 
	///
	///\author	Max Krieger
	///\date	3/11/2015
	///
	///\return	null if it fails, else the terminable reciever.
	///
	virtual TerminableReciever* GetTerminableReciever();

	///
	///\fn	virtual void Terminable::DeregisterAll();
	///
	///\brief	Automatic deregistration method built for GameObject s. Only present here as a pure virtual so that the TerminationMan can invoke it. 
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	virtual void DeregisterAll() = 0;
};

#endif 