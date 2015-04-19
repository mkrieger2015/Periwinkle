#ifndef _CollisionAABB
#define _CollisionAABB

#include "CollisionVolume.h"


///
///\class	CollisionAABB
///\ingroup   Collisions
///\brief	Axis-aligned bounding box used for collisions. More expensive than a sphere, but less expensive than an oriented bounding box. Useful for static objects. Child of CollisionVolume class.
///
///\author	Max Krieger
///\date	4/6/2015
///
class CollisionAABB : public CollisionVolume
{
protected:
	
	///\brief The GraphicsObject used to detect collisions on this volume. Recommended to be lower-poly than display model (possibly redundant? Will re-visit later). 
	GraphicsObject *collisionModel;

	///\brief The calculated min point of the AABB in local space.
	Vect minPoint;

	///\brief The calculated max point of the AABB in local space.
	Vect maxPoint;

public:
	///
	///\fn CollisionAABB::CollisionAABB(Matrix m);
	///
	///\brief	Constructor. Takes the graphics object of the parent to get world matrix and points of the parent.
	CollisionAABB(GraphicsObject *obj);

	///
	///\fn CollisionAABB::~CollisionAABB();
	///
	///\brief	Destructor. Ensures pointer cleanup.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	~CollisionAABB();

	///
	///\fn	void CollisionSphere::UpdateVolume(Matrix m)
	///
	///\brief	Method for updating world transform data of the collision volume. Should be called every frame the parent is moved in world space. 
	///
	///\author	Max Krieger
	///\date	4/6/2015
	///
	void UpdateVolume() override;

	///
	///\fn	Vect CollisionAABB::ReturnAABBCenter()
	///
	///\brief	Returns the center point of the axis-aligned bounding box
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	Vect ReturnAABBCenter();

	///
	///\fn	Vect CollisionAABB::ReturnAABBScale()
	///
	///\brief	Returns the scale of the axis-aligned bounding box
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	Vect ReturnAABBScale();

	///
	///\fn	Vect CollisionAABB::ReturnMinPoint()
	///
	///\brief	Returns the smallest point on the AABB (NOT the smallest point on the model in local space!)
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	Vect ReturnMinPoint(){return minPoint;};
	
	///
	///\fn	Vect CollisionAABB::ReturnMaxPoint()
	///
	///\brief	Returns the largest point on the AABB (NOT the largest point on the model in local space!)
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	Vect ReturnMaxPoint(){return maxPoint;};

	///
	///\fn	bool CollisionAABB::Accept()
	///
	///\brief	Accepts a visitor for the collision system. Returns true/false from collision test down the chain.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	bool Accept(CollisionVolume *other) override;

	///
	///\fn	bool CollisionAABB::Visit()
	///
	///\brief	Generic visit method. Should not be called, but here as a contingency. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	bool Visit(CollisionVolume *other) override;

	///
	///\fn	bool CollisionAABB::SphereVisit()
	///
	///\brief	Collision event for a sphere against this AABB.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	bool SphereVisit(CollisionSphere *other) override;

	///
	///\fn	bool CollisionAABB::AABBVisit()
	///
	///\brief	Collision event for an AABB against this AABB.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	bool AABBVisit(CollisionAABB *other) override;

	///
	///\fn	bool CollisionAABB::DrawVolume()
	///
	///\brief	Draws a debug wireframe mesh to represent this AABB. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	void DrawVolume() override;

	///
	///\fn	bool CollisionAABB::SetVisibility()
	///
	///\brief	Turn the debug mesh on or off. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	void SetVisibility(bool v) override;

};

#endif 