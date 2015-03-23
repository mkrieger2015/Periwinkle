#include "GameObject.h"
#include "ResourceMan.h"
#include "SceneMan.h"

GameObject::GameObject()
{
	SceneMan::DrawRegistration(this);
	SceneMan::UpdateRegistration(this);
}

GraphicsObjectFlatTexture* GameObject::BuildTextured(std::string texName, std::string modName)
{
	Model* dispModel= ResourceMan::GetModel(modName);
	Texture* dispTexture= ResourceMan::GetTexture(texName);
	GraphicsObjectFlatTexture* dispGraphicsObject= new GraphicsObjectFlatTexture(dispModel, dispTexture);

	return dispGraphicsObject;
}

GraphicsObjectWireFrame* GameObject::BuildWireframe(std::string modName)
{
	Model* dispModel= ResourceMan::GetModel(modName);
	GraphicsObjectWireFrame* dispGraphicsObject= new GraphicsObjectWireFrame(dispModel);

	return dispGraphicsObject;
}

GraphicsObjectFlatTexture* GameObject::BuildTexturedDefault(std::string modName)
{
	return ResourceMan::BuildTexturedDefault(modName);
}

void GameObject::Initialize()
{

}

void GameObject::Draw()
{

}

void GameObject::Update()
{

}

void GameObject::RegisterKeyPress(AZUL_KEY key)
{
	SceneMan::InputPressRegistration(this, key);
}

void GameObject::DeregisterKeyPress(AZUL_KEY key)
{
	SceneMan::InputPressDeregistration(this, key);
}

void GameObject::RegisterKeyRelease(AZUL_KEY key)
{
	SceneMan::InputReleaseRegistration(this, key);
}

void GameObject::DeregisterKeyRelease(AZUL_KEY key)
{
	SceneMan::InputReleaseDeregistration(this, key);
}

void GameObject::OnKeyPress(AZUL_KEY key)
{
	(void)key;
}

void GameObject::OnKeyRelease(AZUL_KEY key)
{
	(void)key;
}

void GameObject::DeregisterAll()
{
	SceneMan::DrawDeregistration(this);
	SceneMan::UpdateDeregistration(this);
}