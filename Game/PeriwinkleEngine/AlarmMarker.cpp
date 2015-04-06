#include "AlarmMarker.h"
#include "Alarmable.h"
#include "TimeMan.h"

AlarmMarker::AlarmMarker(Alarmable* ptr, int id, float time)
{
	callback= ptr;
	alarmID= id;
	alarmTime= time;
}

Alarmable* AlarmMarker::GetCallbackPointer()
{
	return callback;
}

float AlarmMarker::GetAlarmTime()
{
	return alarmTime;
}

int AlarmMarker::GetAlarmID()
{
	return alarmID;
}

void AlarmMarker::TriggerAlarm()
{
	callback->Dispatch(alarmID);
}

AlarmMarker::~AlarmMarker()
{

}