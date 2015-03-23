#include "Collidable.h"
#include <iostream>

void Collidable::Collision(Collidable* col)
{
	std::cout << "Collidable and Collidable" << std::endl;
	col;
}

bool Collidable::TestCollisionPair(Collidable *c1, Collidable *c2)
{
	Matrix m1= (Matrix(SCALE, c1->mainColliderRadius, c1->mainColliderRadius, c1->mainColliderRadius) * Matrix(TRANS, c1->mainColliderCenter))*c1->mainColliderObject->getWorld();
	Matrix m2= (Matrix(SCALE, c2->mainColliderRadius, c2->mainColliderRadius, c2->mainColliderRadius) * Matrix(TRANS, c2->mainColliderCenter))*c2->mainColliderObject->getWorld();

	Vect centerBase= Vect(0,0,0);
	Vect radiusBase= Vect(1,0,0);

	Vect c1CenterAdj;
	c1CenterAdj= centerBase*m1;
	Vect c2CenterAdj;
	c2CenterAdj= centerBase*m2;

	float c1RadiusAdj;
	c1RadiusAdj= Vect(c1CenterAdj - Vect(radiusBase*m1)).mag();

	float c2RadiusAdj;
	c2RadiusAdj= Vect(c2CenterAdj - Vect(radiusBase*m2)).mag();

	float centerDist;
	centerDist= Vect(c1CenterAdj - c2CenterAdj).mag();
	float radiusSum;
	radiusSum= c1RadiusAdj + c2RadiusAdj;

	if(centerDist <= radiusSum)
	{
		return true;
	}
		return false;
}