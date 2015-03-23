#ifndef _DrawableMan
#define _DrawableMan

#include "Azul.h"
#include <string>
#include <list>
#include <iostream>

class Drawable;

///
///\class	DrawableMan
///\ingroup Managers
///\brief	Per-scene manager for all active Drawables.
///
///\author	Max Krieger
///\date	3/4/2015
///

class DrawableMan
{
private:


	///\brief	List of drawables.
	std::list<Drawable*> DrawableList;
public:

	///
	///\fn	DrawableMan::~DrawableMan();
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	~DrawableMan();

	///
	///\fn	void DrawableMan::UpdateAll();
	///
	///\brief	Per-frame update for all active Drawables.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void UpdateAll();

	///
	///\fn	void DrawableMan::Register(Drawable *obj);
	///
	///\brief	Registers a Drawable to the list.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void Register(Drawable *obj);

	///
	///\fn	void DrawableMan::Deregister(Drawable *obj);
	///
	///\brief	Deregisters a Drawable from the list.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///
	void Deregister(Drawable *obj);
};

#endif

