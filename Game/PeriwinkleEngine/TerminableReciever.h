#ifndef _TerminableReciever
#define _TerminableReciever

class Terminable;

///
///\class	TerminableReciever
///\ingroup Managers
///\brief	Base class for the Dumpster, as well as any user-created factories. USERS MUST HAVE THEIR FACTORIES DERIVE FROM THIS CLASS.
///
///\author	Max Krieger
///\date	3/11/2015
///
class TerminableReciever
{
public:
	///
	///\fn	virtual void TerminableReciever::RecieveAction(Terminable *t);
	///
	///\brief	This is the method that is called in a TerminableReciever when a Terminable is sent off to it in order to be processed. 
	///
	///\author	Max Krieger
	///\date	3/11/2015
	///
	///\param [in,out]	t	If non-null, the Terminable * to process.
	///
	virtual void RecieveAction(Terminable *t);
};

#endif 