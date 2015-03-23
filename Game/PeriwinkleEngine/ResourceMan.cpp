#include "ResourceMan.h"
#include <iostream>

ResourceMan* ResourceMan::self = NULL;

void ResourceMan::UnloadAll()
{
	ResourceMan *pMan = &Instance();

	std::map<std::string, Texture*>::iterator itText = pMan->CollectionTextures.begin();
	std::map<std::string, Model*>::iterator itModel = pMan->CollectionModels.begin();

	Texture* pText= NULL;
	Model* pModel= NULL;

	while(itText != pMan->CollectionTextures.end())
	{
		pText = itText->second;
		++itText;

		if(pText)
		{
			delete pText;
		}
	}

	while(itModel != pMan->CollectionModels.end())
	{
		pModel = itModel->second;
		++itModel;

		if(pModel)
		{
			delete pModel;
		}
	}

	delete self;
}

void ResourceMan::AddTexture(std::string keyword, std::string filename)
{
	if (keyword.size() == 0 || filename.size() == 0)
	{
		//not a valid key/name
		std::cout << "You forgot to pass in a keyword or filename!" << std::endl;
	}
	else
	{
		std::map< std::string, Texture*>::iterator it;
		it= Instance().CollectionTextures.find(keyword);
		if(it != Instance().CollectionTextures.end())
		{
		std::cout << "Texture with keyword " << keyword.c_str() << " already loaded!" << std::endl;
		}
		else
		{
			Instance().CollectionTextures[keyword] = GpuTexture::Create(filename.c_str());
			std::cout << "Current # of elements in texture collection: " << Instance().CollectionTextures.size() << std::endl;
		}
	}
}


Texture* ResourceMan::GetTexture(std::string keyword)
{
	std::map< std::string, Texture*>::iterator it;
	it= Instance().CollectionTextures.find(keyword);
	if(it == Instance().CollectionTextures.end())
	{
		std::cout << "Failed to find loaded texture " << keyword.c_str() << " ! Did you add it?" << std::endl;
		//to do: return pink texture
	}
	return it->second;
}

void ResourceMan::AddModel(std::string keyword, std::string filename)
{
	if (keyword.size() == 0 || filename.size() == 0)
	{
		//not a valid key/name
		std::cout << "Invalid keyword or filename" << std::endl;
	}

	std::map< std::string, Model*>::iterator it;
	it= Instance().CollectionModels.find(keyword);
	if(it != Instance().CollectionModels.end())
	{
		std::cout << "Model with keyword " << keyword.c_str() << " already loaded!" << std::endl;
	}
	else
	{
		Instance().CollectionModels[keyword] = GpuModel::Create(filename.c_str());
		std::cout << "Current # of elements in texture collection: " << Instance().CollectionModels.size() << std::endl;
	}
}

Model* ResourceMan::GetModel(std::string keyword)
{
	std::map< std::string, Model*>::iterator it;
	it= Instance().CollectionModels.find(keyword);
	if(it == Instance().CollectionModels.end())
	{
		std::cout << "Failed to find loaded model " << keyword.c_str() << " ! Did you add it?" << std::endl;
	}
	return it->second;
}

GraphicsObjectFlatTexture* ResourceMan::BuildTexturedDefault(std::string keyword)
{
	Model* dispModel= ResourceMan::GetModel(keyword);
	Texture *pTexModel[4];
	std::cout << "Num of textures on this model: " << dispModel->numTextures << std::endl;
	for( int i=0; i< dispModel->numTextures; i++)
	{
		char *pTextureName = dispModel->getTextureName(i);
		pTexModel[i] = GpuTexture::Create(pTextureName);		
	}

	if(dispModel->numTextures == 1)
		return new GraphicsObjectFlatTexture( dispModel, pTexModel[0]);
	else if (dispModel->numTextures == 2)
		return new GraphicsObjectFlatTexture( dispModel, pTexModel[0], pTexModel[1]);
	else if (dispModel->numTextures == 3)
		return new GraphicsObjectFlatTexture( dispModel, pTexModel[0], pTexModel[1], pTexModel[2]);
	else if (dispModel->numTextures == 4)
		return new GraphicsObjectFlatTexture( dispModel, pTexModel[0], pTexModel[1], pTexModel[2], pTexModel[3]);
	else
		return NULL;
}