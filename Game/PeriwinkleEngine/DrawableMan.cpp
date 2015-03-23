#include "DrawableMan.h"
#include "Drawable.h"

void DrawableMan::Register(Drawable *obj)
{
	bool found;
	found= false;
	std::list<Drawable*>::iterator it;
	it = DrawableList.begin();
	Drawable *temp;
	while (it != DrawableList.end() && found == false)
	{
		temp= (*it);
		if(temp == obj)
		{
			found= true; 
			std::cout << "Drawable already registered (DEBUG)" << std::endl;
		}
		it++;
	}
	if (found == false)
	{
		DrawableList.push_front(obj);
	}
}

void DrawableMan::Deregister(Drawable *obj)
{
	bool found;
	found= false;
	std::list<Drawable*>::iterator it;
	it = DrawableList.begin();
	Drawable *temp;
	while (it != DrawableList.end() && found == false)
	{
		temp= (*it);
		if (temp == obj)
		{
			found= true;
			DrawableList.erase(it++);
		}
		else
			it++;
	}
	if (found == false)
	{
		std::cout << "Attempted dereg of unregistered Drawable (DEBUG)" << std::endl;
	}
}

void DrawableMan::UpdateAll()
{
	std::list<Drawable*>::iterator it;
	it = DrawableList.begin();
	while (it != DrawableList.end())
	{
		(*it)->Draw();
		it++;
	}
}

DrawableMan::~DrawableMan()
{
	//std::cout << "Look, mah, I have a destructor!" << std::endl;
}