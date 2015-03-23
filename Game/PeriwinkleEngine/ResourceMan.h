#ifndef _ResourceMan
#define _ResourceMan

#include <iostream>
#include <string>
#include <map>
#include "Azul.h"

struct Texture;
class Model;

///
///\class	ResourceMan
///\ingroup Resources
///\brief	Singleton manager for all assets and resources. LoadAllContent is a user-defined method to be found in the Content subdirectory.
///
///\author	Max Krieger
///\date	3/4/2015
///

class ResourceMan
{
private: 

	///\brief	Pointer to self for singleton access.
	static ResourceMan *self;

	///
	///\fn	ResourceMan::ResourceMan()
	///
	///\brief	Default constructor. Empty (singleton).
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	ResourceMan(){ };

	///
	///\fn	ResourceMan::ResourceMan(const ResourceMan&)
	///
	///\brief	Copy constructor. Empty (singleton).
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	ResourceMan(const ResourceMan&){ };

	///
	///\fn	ResourceMan& ResourceMan::operator= (const ResourceMan&)
	///
	///\brief	Assignment operator for shallow copy. Empty (singleton).
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	ResourceMan& operator= (const ResourceMan&){ };

	///
	///\fn	ResourceMan::~ResourceMan()
	///
	///\brief	Destructor. Empty (singleton).
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	~ResourceMan(){ };

	///
	///\fn	static ResourceMan& ResourceMan::Instance()
	///
	///\brief	Returns instance of singleton. If ResourceMan has not been created yet, create it. Otherwise, return reference to instance. Accessor for all public static methods.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\return	A ResourceMan&amp;
	///
	static ResourceMan& Instance()
	{
		if (!self)
			self= new ResourceMan();
		return *self;
	};


	///\brief	The collection of loaded textures.
	std::map< std::string, Texture*> CollectionTextures;


	///\brief	The collection of loaded models.
	std::map< std::string, Model*> CollectionModels;

public:

	///
	///\fn	static void ResourceMan::AddTexture(std::string keyword, std::string filename);
	///
	///\brief	Adds a texture to the collection. Loads from filename, stores it under a string keyword.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param	keyword 	The keyword.
	///\param	filename	Filename of the file.
	///
	static void AddTexture(std::string keyword, std::string filename);

	///
	///\fn	static Texture* ResourceMan::GetTexture(std::string keyword);
	///
	///\brief	Gets a texture from the collection, identified by keyword. 
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param	keyword	The keyword.
	///
	///\return	null if it fails, else the texture.
	///
	static Texture* GetTexture(std::string keyword);

	///
	///\fn	static void ResourceMan::AddModel(std::string keyword, std::string filename);
	///
	///\brief	Adds a model to the collection. Loads from filename, stores it under a string keyword.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param	keyword 	The keyword.
	///\param	filename	Filename of the file.
	///
	static void AddModel(std::string keyword, std::string filename);

	///
	///\fn	static Model* ResourceMan::GetModel(std::string keyword);
	///
	///\brief	Gets a model from the collection, identified by keyword.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\param	keyword	The keyword.
	///
	///\return	null if it fails, else the model.
	///
	static Model* GetModel(std::string keyword);

	///
	///\fn	static GraphicsObjectFlatTexture* ResourceMan::BuildTexturedDefault(std::string keyword);
	///
	///\brief	Used to build and return a GraphicsObject with its default textures. NOTE: IF YOUR MODEL DOES NOT HAVE DEFAULT TEXTURES, THIS METHOD WILL RETURN THE DEFAULT MISSING TEXTURE.
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	///\param	keyword	The keyword.
	///
	///\return	null if it fails, else a GraphicsObjectFlatTexture*.
	///
	static GraphicsObjectFlatTexture* BuildTexturedDefault(std::string keyword);

	///
	///\fn	static void ResourceMan::LoadAllContent();
	///
	///\brief	User-defined method to load all models and textures at once. Can be found in the Content subdirectory, under LoadAllContent.cpp.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void LoadAllContent();

	///
	///\fn	static void ResourceMan::UnloadAll();
	///
	///\brief	Unloads all content from collections. Called at shutdown.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void UnloadAll();
};

#endif