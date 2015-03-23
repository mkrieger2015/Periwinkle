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

void AlarmMarker::TriggerAlarm()
{
	callback->Dispatch(alarmID);
}

void AlarmMarker::AddTime(float time)
{
	alarmTime += time;
}

void AlarmMarker::SubtractTime(float time)
{
	if(alarmTime - time > TimeMan::GetTotalTime())
	{
		alarmTime -= time;
	}
	else
	{
		alarmTime= TimeMan::GetTotalTime();
	}
}

AlarmMarker::~AlarmMarker()
{

}