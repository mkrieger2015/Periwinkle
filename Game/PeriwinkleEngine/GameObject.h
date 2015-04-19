#ifndef _GameObject
#define _GameObject

#include "Azul.h"
#include "Inputable.h"
#include "Drawable.h"
#include "Updateable.h"
#include "Alarmable.h"
#include "Collidable.h"
#include "Terminable.h"
#include <string>
#include <iostream>

///
///\class	GameObject
///\ingroup GameObject
///\brief	The base GameObject class. This is the ONLY engine-level class the user should derive their own defined game objects from. Inherits from Inputable, Drawable, Updateable, Alarmable, Collidable, and Terminable. 
///
///\author	Max Krieger
///\date	3/4/2015
///
class GameObject : public Inputable, public Drawable, public Updateable, public Alarmable, public Collidable, public Terminable
{

protected: 

	///\brief	The object's transform matrix.
	Matrix world;

	///\brief	The rotation to be used in the transform matrix.
	Matrix Rot;

	///\brief	The scale to be used in the transform matrix.
	Vect Scale;

	///\brief	The translation to be used in the transform matrix.
	Vect Trans;

	///
	///\fn	void GameObject::BuildTextured(std::string texName, std::string modName);
	///
	///\brief	Builds this game object as a textured game object. EITHER THIS, BuildTexturedDefault, or BuildWireframe MUST BE CALLED IN YOUR OBJECT'S CONSTRUCTOR. The texture name and model name passed in as parameters will be searched for in the ResourceMan to build the graphics model for this object - make sure the assets are loaded in.
	///
	///\author	Max Krieger
	///\date	3/10/2015
	///
	///\param	texName	Name of the tex.
	///\param	modName	Name of the modifier.
	///
	virtual GraphicsObjectFlatTexture* BuildTextured(std::string texName, std::string modName);

	///
	///\fn	void GameObject::BuildWireframe(std::string modName) virtual ~GameObject()
	///
	///\brief	Builds this game object as a wireframe game object. EITHER THIS, BuildTexturedDefault or BuildTextured MUST BE CALLED IN YOUR OBJECT'S CONSTRUCTOR. The model name passed in as parameter will be searched for in the ResourceMan to build the graphics model for this object - make sure that model is loaded in. Wire frame material is preloaded.
	///
	///\author	Max Krieger
	///\date	3/10/2015
	///
	///\param	modName	Name of the modifier.
	///
	virtual GraphicsObjectWireFrame* BuildWireframe(std::string modName);

	///
	///\fn	virtual GraphicsObjectFlatTexture* GameObject::BuildTexturedDefault(std::string modName);
	///
	///\brief	Builds this game object as a textured game object. NOTE THAT IF YOUR MODEL DOES NOT HAVE DEFAULT TEXTURES, THIS METHOD WILL NOT WORK. EITHER THIS, BuildTextured, or BuildWireframe MUST BE CALLED IN YOUR OBJECT'S CONSTRUCTOR. The model name passed in as parameters will be searched for in the ResourceMan to build the graphics model for this object - make sure the model is loaded in.
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	///\param	modName	Name of the modifier.
	///
	///\return	null if it fails, else a GraphicsObjectFlatTexture*.
	///
	virtual GraphicsObjectFlatTexture* BuildTexturedDefault(std::string modName);

private: 
	///
	///\fn	virtual void GameObject::Initialize();
	///
	///\brief	This is where the user will define what the game object should do when it is initialized. This is called from the Game Object's constructor. DO NOT TRY TO REDEFINE THE CONSTRUTOR - it is not virtual. 
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	virtual void Initialize();

	///
	///\fn	virtual void GameObject::Draw();
	///
	///\brief	Draw event. This is the virtual event where the user will issue draw calls to all things in the object they'd like to draw.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void Draw();

	///
	///\fn	virtual void GameObject::Update();
	///
	///\brief	Update event. Since it's virtual, this is where the user can define any things they'd like their object to do or check at each update.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void Update();

	///
	///\fn	virtual void GameObject::OnKeyPress(AZUL_KEY key);
	///
	///\brief	This is the virutal (overwriteable) method that they key object calls whenever it detects that this object is interested in knowing about a certain key PRESS. It passes in its key value - the user should test for all the different keys they are interested in here, and define what each key ought to do.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void OnKeyPress(AZUL_KEY key);

	///
	///\fn	virtual void GameObject::OnKeyRelease(AZUL_KEY key);
	///
	///\brief	This is the virutal (overwriteable) method that they key object calls whenever it detects that this object is interested in knowing about a certain key RELEASE. It passes in its key value - the user should test for all the different keys they are interested in here, and define what each key ought to do.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void OnKeyRelease(AZUL_KEY key);

	///
	///\fn	virtual void GameObject::OnDestroy()
	///
	///\brief	The method called when this object is destroyed, AFTER it has been marked by destroy. NOT CALLED BY DUMPSTER!
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void OnDestroy(){};

	///
	///\fn	virtual void GameObject::DeregisterAll();
	///
	///\brief	Auto-deregistration method for GameObjects. 
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	virtual void DeregisterAll();

public:

	///
	///\fn	GameObject::GameObject();
	///
	///\brief	Default constructor. Automatically registers a GameObject for draw and update upon creation. If you don't want a GameObject to be updated or drawn, make sure to deregister it via SceneMan accessors in the Initialize method.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	GameObject();

	///
	///\fn	virtual GameObject::~GameObject()
	///
	///\brief	Destructor. Since it's virtual, this is where the user can define any things they'd like their object to do upon being destroyed while NOT marked. THIS IS CALLED BY THE DUMPSTER!
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual ~GameObject(){};

		///
	///\fn	virtual void GameObject::RegisterKeyPress(AZUL_KEY key);
	///
	///\brief	Registers this object to the InputManager for a key press event. The key you pass in here will be the key detected.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void RegisterKeyPress(AZUL_KEY key);

	///
	///\fn	virtual void GameObject::DeregisterKeyPress(AZUL_KEY key);
	///
	///\brief Deregisters this object to the InputManager from a key press event. The key you pass in here will seeked out, and any callbacks involving this object will be removed from that key's list of callbacks.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void DeregisterKeyPress(AZUL_KEY key);

	///
	///\fn	virtual void GameObject::RegisterKeyRelease(AZUL_KEY key);
	///
	///\brief	Registers this object to the InputManager for a key release event on key key. The key you pass in here will be the key detected.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void RegisterKeyRelease(AZUL_KEY key);

	///
	///\fn	virtual void GameObject::DeregisterKeyRelease(AZUL_KEY key);
	///
	///\brief	Deregisters this object to the InputManager from a key release event on key key. The key you pass in here will seeked out, and any callbacks involving this object will be removed from that key's list of callbacks.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	key	The key.
	///
	virtual void DeregisterKeyRelease(AZUL_KEY key);

};

#endif

