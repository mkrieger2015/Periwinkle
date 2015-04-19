#include "../PeriwinkleEngine/ResourceMan.h"

void ResourceMan::LoadAllContent()
{
	// Converting models from FBX format to AZUL format
	printf("Converting FBX to AZUL\n");

	//you MUST convert all models you plan on using into the .azul format with this next line of code
	//repeat system call as needed, with the name of your fbx file you wish to convert
	//the BoundingSphere.azul has already been pre-converted
	system("ConverterDebug space_frigate.fbx > DebugInfo.txt");
	system("ConverterDebug Cottage.fbx > DebugInfo.txt");
	system("ConverterDebug Plane.fbx > DebugInfo.txt");

	printf("Converting completed\n");

	ResourceMan::AddTexture("spaceFrigate", "space_frigate.tga");

	ResourceMan::AddModel("spaceFrigate", "space_frigate.azul");

	ResourceMan::AddModel("UnitSphere","BoundingSphere.azul");

	ResourceMan::AddModel("UnitCube","BoundingBox.azul");

	ResourceMan::AddTexture("Cube", "brick-wall.tga");

	ResourceMan::AddModel("Cottage", "Cottage.azul");

	ResourceMan::AddTexture("Grid", "grid.tga");

	ResourceMan::AddModel("Plane", "Plane.azul");
}