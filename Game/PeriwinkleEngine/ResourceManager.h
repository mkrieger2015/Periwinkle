#ifndef _ResourceMan
#define _ResourceMan

#include <map>
//#include "Azul.h"


class ResourceManager
{
	private: 
	static ResourceManager *self;

	ResourceManager(){ };
	ResourceManager(const ResourceManager&){ };
	ResourceManager& operator= (const ResourceManager&){ };

	~ResourceManager(){ };
	
	static ResourceManager& Instance()
	{
		if (!self)
			self= new ResourceManager();
		return *self;
	};

public:
	static void Test();

};

#endif