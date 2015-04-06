#ifndef _AlarmMarker
#define _AlarmMarker

#include "Azul.h"
#include "TimeMan.h"

class Alarmable;

///
///\class	AlarmMarker
///\ingroup Alarms
///\brief	This is the object inserted into the alarm timeline that triggers its callback at the appropriate time.
///
///\author	Max Krieger
///\date	3/4/2015
///

class AlarmMarker
{
private:
	
	///\brief	This indicates which alarm event, 0, 1, or 2, will be executed in the callback.
	int alarmID;

	///\brief	The callback.
	Alarmable* callback;

	///\brief	The alarm time.
	float alarmTime;
public:

	///
	///\fn	AlarmMarker::AlarmMarker(Alarmable* ptr, int id, float time);
	///
	///\brief	Constructor.
	///
	///\author	Max Krieger
	///\date	3/2/2015
	///
	///\param [in,out]	ptr	If non-null, the pointer.
	///\param	id		   	Which alarm is to be triggered (0, 1, or 2).
	///\param	time	   	Amount of time before alarm goes off.
	///

	AlarmMarker(Alarmable* ptr, int id, float time);

	///
	///\fn	AlarmMarker::~AlarmMarker();
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/2/2015
	///
	~AlarmMarker();

	///
	///\fn	Alarmable* AlarmMarker::GetCallbackPointer();
	///
	///\brief	Returns callback pointer.
	///
	///\author	Max Krieger
	///\date	3/2/2015
	///
	///\return	null if it fails, else the callback pointer.
	///
	Alarmable* GetCallbackPointer();

	///
	///\fn	float AlarmMarker::GetAlarmTime();
	///
	///\brief	Returns alarm time.
	///
	///\author	Max Krieger
	///\date	3/2/2015
	///
	///\return	The alarm time.
	///
	float GetAlarmTime();

	///
	///\fn	int AlarmMarker::GetAlarmID();
	///
	///\brief	Returns alarm ID (used to trigger proper alarm in callback).
	///
	///\author	Max Krieger
	///\date	4/5/2015
	///
	///\return	The alarm ID.
	///
	int GetAlarmID();

	///
	///\fn	void AlarmMarker::TriggerAlarm();
	///
	///\brief	Triggers the Dispatch method in the callback Alarmable, passing in the alarmID member.
	///
	///\author	Max Krieger
	///\date	3/2/2015
	///
	void TriggerAlarm();

};

#endif

