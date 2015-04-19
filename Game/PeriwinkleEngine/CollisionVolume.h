#ifndef _CollisionVolume
#define _CollisionVolume

#include "Azul.h"

///
///\class	CollisionVolume
///\ingroup   Collisions
///\brief	Parent class for all collision volumes (spheres, AABBs, etc.). 
///
///\author	Max Krieger
///\date	4/6/2015
///

class CollisionSphere;
class CollisionAABB;

class CollisionVolume
{
protected:

	///\brief Whether this object's mesh is to be drawn or not. 
	bool drawn;

	///\brief The mesh used to detect collisions on this collision volume. 
	GraphicsObjectWireFrame *collisionMesh;

public:
	///
	///\fn	virtual void CollisionVolume::UpdateVolume(Matrix m)
	///
	///\brief	Abstract method for updating world transform data of the collision volume. Should be called every frame the parent is moved in world space. 
	///
	///\author	Max Krieger
	///\date	4/6/2015
	///
	virtual void UpdateVolume()= 0; 

	///
	///\fn	bool CollisionVolume::Accept()
	///
	///\brief	Abstract accept method for collision visitor pattern. Returns true/false from collision test down the chain.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	virtual bool Accept(CollisionVolume *other)= 0;

	///
	///\fn	bool CollisionVolume::Visit()
	///
	///\brief	Abstract generic visit method. Should not be called, but here as a contingency. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	virtual bool Visit(CollisionVolume *other)= 0;

	///
	///\fn	bool CollisionVolume::SphereVisit()
	///
	///\brief	Abstract collision event for a sphere against a collision volume.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	virtual bool SphereVisit(CollisionSphere *other)= 0;

	///
	///\fn	bool CollisionVolume::AABBVisit()
	///
	///\brief	Abstract collision event for an AABB against a collision volume.
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	virtual bool AABBVisit(CollisionAABB *other)= 0;

	///
	///\fn	void CollisionVolume::DrawVolume()
	///
	///\brief	Abstract method to draw a debug wireframe mesh representing the collision volume. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	virtual void DrawVolume()= 0;

	///
	///\fn	void CollisionVolume::SetVisibility()
	///
	///\brief	Abstract method to turn debug mesh drawing on or off. 
	///
	///\author	Max Krieger
	///\date	4/15/2015
	///
	virtual void SetVisibility(bool v)= 0;

};

#endif