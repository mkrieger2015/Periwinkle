#include "Scene.h"

#include "InputableMan.h"
#include "DrawableMan.h"
#include "UpdateableMan.h"
#include "AlarmMan.h"
#include "CollisionMan.h"
#include "TerminationMan.h"
#include "Dumpster.h"


Scene::Scene()
{
	am= new AlarmMan();
	im= new InputableMan();
	dm= new DrawableMan();
	um= new UpdateableMan();
	cm= new CollisionMan();
	tm= new TerminationMan();
	dmp= new Dumpster();
}

void Scene::UpdateAlarmMan()
{
	am->UpdateAlarms();
}

void Scene::UpdateInputableMan()
{
	im->CheckKeyStatus();
}

void Scene::UpdateDrawableMan()
{
	dm->UpdateAll();
}

void Scene::UpdateUpdateableMan()
{
	um->UpdateAll();
}

void Scene::UpdateCollisionMan()
{
	cm->ProcessCollisions();
}

void Scene::AlarmRegistration(Alarmable *obj, int alarmID, float time)
{
	am->Register(obj, alarmID, time);
}

void Scene::DrawRegistration(Drawable *obj)
{
	dm->Register(obj);
}

void Scene::InputPressRegistration(Inputable *obj, AZUL_KEY key)
{
	im->RegisterKeyPress(obj, key);
}

void Scene::InputReleaseRegistration(Inputable *obj, AZUL_KEY key)
{
	im->RegisterKeyRelease(obj, key);
}

void Scene::UpdateRegistration(Updateable *obj)
{
	um->Register(obj);
}

void Scene::AlarmDeregistration(Alarmable *obj, float time)
{
	am->Deregister(obj, time);
}

void Scene::AddAlarmTime(Alarmable *obj, float time, float timeAdded)
{
	am->AddAlarmTime(obj, time, timeAdded);
}

void Scene::SubtractAlarmTime(Alarmable *obj, float time, float timeSubtracted)
{
	am->SubtractAlarmTime(obj, time, timeSubtracted);
}

void Scene::DrawDeregistration(Drawable *obj)
{
	dm->Deregister(obj);
}

void Scene::InputPressDeregistration(Inputable *obj, AZUL_KEY key)
{
	im->DeregisterKeyPress(obj, key);
}

void Scene::InputReleaseDeregistration(Inputable *obj, AZUL_KEY key)
{
	im->DeregisterKeyRelease(obj, key);
}

void Scene::UpdateDeregistration(Updateable *obj)
{
	um->Deregister(obj);
}

void Scene::MarkForDestroy(Terminable *obj)
{
	tm->MarkForDestroy(obj);
}

void Scene::DestroyMarked()
{
	tm->UpdateAll();
}

void Scene::DumpsterRegistration(Terminable *obj)
{
	dmp->Register(obj);
}

void Scene::DumpsterDeregistration(Terminable *obj)
{
	dmp->Deregister(obj);
}

void Scene::EmptyDumpster()
{
	dmp->DeleteAll();
}

Dumpster* Scene::ReturnDumpster()
{
	return dmp;
}

void Scene::Cleanup()
{

}

void Scene::InitializeScene()
{

}

void Scene::LoadContentScene()
{

}

void Scene::UpdateScene()
{

}

void Scene::DrawScene()
{

}

void Scene::UnLoadContentScene()
{

}

void Scene::OnSceneEnd()
{

}

Scene::~Scene()
{
	dmp->DeleteAll();
	delete am;
	delete im;
	delete dm;
	delete um;
	delete cm;
	delete tm;
	delete dmp;
}