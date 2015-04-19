#include "Collidable.h"
#include "CollisionVolume.h"
#include <iostream>

#include "CollisionVolume.h"

Collidable::Collidable()
{
	solid= false;
	colVol= NULL;
}

void Collidable::Collision(Collidable* col)
{
	std::cout << "Collidable and Collidable" << std::endl;
	col;
}

bool Collidable::TestCollisionPair(Collidable *c1, Collidable *c2)
{
	return c1->colVol->Accept(c2->colVol);
}

void Collidable::UpdateCollidable()
{
	if(solid == false && colVol != NULL)
	{
		colVol->UpdateVolume();
	}
}