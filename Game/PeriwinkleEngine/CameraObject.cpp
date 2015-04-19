#include "CameraObject.h"
#include "SceneMan.h"

CameraObject::CameraObject(Vect *up, Vect *pos, Vect *look)
{
	CamUpdate(up, pos, look);
}

void CameraObject::CamUpdate(Vect *up, Vect *pos, Vect *look)
{
	camUp= *up;
	camPos= *pos;
	camTarget= *look;
	CameraMan::GetCurrent()->setOrientAndPosition( camUp, camTarget, camPos);
	CameraMan::GetCurrent()->updateCamera();
}