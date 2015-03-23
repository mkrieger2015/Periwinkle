#include "SceneMan.h"
#include "Scene.h"
#include "Drawable.h"
#include "Inputable.h"
#include "Updateable.h"
#include "Terminable.h"

#include <iostream>


SceneMan* SceneMan::self = NULL;

void SceneMan::Initialize()
{

}

void SceneMan::SetCurScene(Scene* scene)
{
	bool sceneLoaded;
	sceneLoaded= false;
	std::list<Scene*>::iterator it;
	it = Instance().sceneList.begin();

	while (it != Instance().sceneList.end() && sceneLoaded == false)
	{
		if((*it) == scene)
		{
			Instance().curScene= (*it);
			sceneLoaded= true;
		}
		it++;
	}
	if (sceneLoaded == false)
	{
		Instance().curScene= scene;
		Instance().sceneList.push_front(Instance().curScene);
	}
	Instance().nextScene = Instance().curScene;

}

void SceneMan::NextScene(Scene* next)
{
	bool sceneLoaded;
	sceneLoaded= false;
	std::list<Scene*>::iterator it;
	it = Instance().sceneList.begin();

	while (it != Instance().sceneList.end() && sceneLoaded == false)
	{
		if((*it) == next)
		{
			Instance().nextScene= (*it);
			sceneLoaded= true;
		}
		it++;
	}
	if (sceneLoaded == false)
	{
		Instance().nextScene= next;
		Instance().sceneList.push_front(Instance().nextScene);
	}

	std::cout << "No. of Scenes in scene list: " << Instance().sceneList.size() << std::endl;
}

void SceneMan::CheckScene()
{
	if(Instance().curScene != Instance().nextScene)
	{
		Instance().curScene->OnSceneEnd();

		std::list<Scene*>::iterator it;
		it= Instance().sceneList.begin();
		bool found;
		found= false;

		while(it != Instance().sceneList.end() && found == false)
		{
			if((*it) == Instance().curScene)
			{
				Instance().sceneList.erase(it++);
				found= true;
			}
			else
			{
				it++;
			}
		}
	
		delete Instance().curScene;
		SetCurScene(Instance().nextScene);
		Instance().LoadContentCurScene();
	}
}

void SceneMan::UpdateCurAlarmables()
{
	Instance().curScene->UpdateAlarmMan();
}

void SceneMan::UpdateCurDrawables()
{
	Instance().curScene->UpdateDrawableMan();
}

void SceneMan::UpdateCurInputables()
{
	Instance().curScene->UpdateInputableMan();
}

void SceneMan::UpdateCurUpdateables()
{
	Instance().curScene->UpdateUpdateableMan();
}

void SceneMan::UpdateCurCollidables()
{
	Instance().curScene->UpdateCollisionMan();
}

void SceneMan::AlarmRegistration(Alarmable *obj, int alarmID, float time)
{
	Instance().curScene->AlarmRegistration(obj, alarmID, time);
}

void SceneMan::DrawRegistration(Drawable *obj)
{
	Instance().curScene->DrawRegistration(obj);
}

void SceneMan::InputPressRegistration(Inputable *obj, AZUL_KEY key)
{
	Instance().curScene->InputPressRegistration(obj, key);
}

void SceneMan::InputReleaseRegistration(Inputable *obj, AZUL_KEY key)
{
	Instance().curScene->InputReleaseRegistration(obj, key);
}

void SceneMan::UpdateRegistration(Updateable *obj)
{
	Instance().curScene->UpdateRegistration(obj);
}

void SceneMan::AlarmDeregistration(Alarmable *obj, float time)
{
	Instance().curScene->AlarmDeregistration(obj,time);
}

void SceneMan::AddAlarmTime(Alarmable *obj, float time, float timeAdded)
{
	Instance().curScene->AddAlarmTime(obj, time, timeAdded);
}

void SceneMan::SubtractAlarmTime(Alarmable *obj, float time, float timeSubtracted)
{
	Instance().curScene->SubtractAlarmTime(obj, time, timeSubtracted);
}

void SceneMan::DrawDeregistration(Drawable *obj)
{
	Instance().curScene->DrawDeregistration(obj);
}

void SceneMan::InputPressDeregistration(Inputable *obj, AZUL_KEY key)
{
	Instance().curScene->InputPressDeregistration(obj, key);
}

void SceneMan::InputReleaseDeregistration(Inputable *obj, AZUL_KEY key)
{
	Instance().curScene->InputPressDeregistration(obj, key);
}

void SceneMan::UpdateDeregistration(Updateable *obj)
{
	Instance().curScene->UpdateDeregistration(obj);
}

void SceneMan::MarkForDestroy(Terminable *obj)
{
	Instance().curScene->MarkForDestroy(obj);
}

void SceneMan::DestroyMarked()
{
	Instance().curScene->DestroyMarked();
}

void SceneMan::InitializeCurScene()
{
	Instance().curScene->InitializeScene();
}

void SceneMan::LoadContentCurScene()
{
	Instance().curScene->LoadContentScene();
}

void SceneMan::UpdateCurScene()
{
	Instance().curScene->UpdateScene();
}

void SceneMan::DrawCurScene()
{
	Instance().curScene->DrawScene();
}

void SceneMan::UnLoadCurContentScene()
{
	Instance().curScene->UnLoadContentScene();
}

void SceneMan::UnloadAll()
{
	std::cout << "No. of scenes in scene list: " << Instance().sceneList.size() << std::endl;
	std::list<Scene*>::iterator it;
	it= Instance().sceneList.begin();
	Scene* temp;
	while(it != Instance().sceneList.end())
	{
		temp= (*it);
		temp->UnLoadContentScene();
		Instance().sceneList.erase(it++);
		delete temp;
	}

	delete self;
}

void SceneMan::DumpsterRegistration(Terminable *obj)
{
	Instance().curScene->DumpsterRegistration(obj);
}

void SceneMan::DumpsterDeregistration(Terminable *obj)
{
	Instance().curScene->DumpsterDeregistration(obj);
}

void SceneMan::EmptyDumpster()
{
	Instance().curScene->EmptyDumpster();
}

Dumpster* SceneMan::ReturnSceneDumpster()
{
	return Instance().curScene->ReturnDumpster();
}