#ifndef _CameraObject
#define _CameraObject

#include "Azul.h"

class CameraObject
{
private:
	Vect camUp;
	Vect camPos;
	Vect camTarget;

public:

	CameraObject(Vect *up, Vect *pos, Vect *look);

	void CamUpdate(Vect *up, Vect *pos, Vect *look);
};

#endif