#ifndef _CollisionSphere
#define _CollisionSphere

#include "CollisionVolume.h"

///
///\class	CollisionSphere
///\ingroup   Collisions
///\brief	Bounding sphere used for collisions. Cheap, but inaccurate. Child of CollisionVolume class.
///
///\author	Max Krieger
///\date	4/6/2015
///
class CollisionSphere : public CollisionVolume
{
protected:

	///\brief The mesh used to detect collisions on this collision volume (possibly redundant? will revisit later).
	GraphicsObject* object;

	///\brief The center of the mesh in local space.
	Vect center;

	///\brief The radius of the mesh.
	float radius;

	///\brief Adjusted world transform.
	Matrix worldAdjust;

	///\brief Adjusted center in world space.
	Vect centerAdjust;

	///\brief Adjusted radius value. 
	float radiusAdjust;


public:
	///
	///\fn CollisionSphere::CollisionSphere(Matrix m);
	///
	///\brief	Constructor. Takes the graphics object of the parent to get world matrix, center, and radius data.
	///\author	Max Krieger
	///\date	4/6/2015
	///
	CollisionSphere(GraphicsObject *obj);

	///
	///\fn CollisionSphere::~CollisionSphere();
	///
	///\brief	Destructor. Ensures pointer cleanup.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	~CollisionSphere();

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
	///\fn	bool CollisionSphere::Accept()
	///
	///\brief	Accept method for collision visitor pattern. Returns true/false from collision test down the chain.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	bool Accept(CollisionVolume *other) override;

	///
	///\fn	bool CollisionSphere::Visit()
	///
	///\brief	Generic visit method. Should not be called, but here as a contingency. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	bool Visit(CollisionVolume *other) override;

	///
	///\fn	bool CollisionSphere::SphereVisit()
	///
	///\brief	Collision event for a sphere against this sphere.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	bool SphereVisit(CollisionSphere *other) override;

	///
	///\fn	bool CollisionSphere::AABBVisit()
	///
	///\brief	Collision event for an AABB against this sphere. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	bool AABBVisit(CollisionAABB *other) override;

	///
	///\fn	Vect CollisionSphere::ReturnSphereCenter()
	///
	///\brief	Returns the WORLD-ADJUSTED center for this sphere (not the center in local space). 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	Vect ReturnSphereCenter(){return centerAdjust;};

	///
	///\fn	float CollisionSphere::ReturnSphereRadius()
	///
	///\brief	Returns the WORLD-ADJUSTED radius for this sphere (e.g. scaled appropriately). 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	float ReturnSphereRadius(){return radiusAdjust;};

	///
	///\fn	void CollisionSphere::DrawVolume()
	///
	///\brief	Method to draw a debug wireframe mesh representing the collision sphere. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	void DrawVolume() override;

	///
	///\fn	void CollisionSphere::SetVisibility()
	///
	///\brief	Method to turn debug mesh drawing on or off. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	void SetVisibility(bool v) override;

};

#endif