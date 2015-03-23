#include "Alarmable.h"
#include "SceneMan.h"
#include "TimeMan.h"

void Alarmable::Alarm0()
{

}

void Alarmable::Alarm1()
{

}

void Alarmable::Alarm2()
{

}

void Alarmable::Dispatch(int alarmID)
{
	if(alarmID == 0)
	{
		Alarm0();
	}
	else if (alarmID == 1)
	{
		Alarm1();
	}
	else if (alarmID == 2)
	{
		Alarm2();
	}
}

void Alarmable::SetAlarm(int alarmID, float time)
{
	float realTime;
	realTime= time + TimeMan::GetTotalTime();
	SceneMan::AlarmRegistration(this, alarmID, realTime);
	curTimes[alarmID]= realTime;
}

void Alarmable::ClearAlarm(int alarmID)
{
	SceneMan::AlarmDeregistration(this,curTimes[alarmID]);
}

void Alarmable::AddTime(int alarmID, float time)
{
	SceneMan::AddAlarmTime(this, curTimes[alarmID], time);
	curTimes[alarmID] += time;
}

void Alarmable::SubtractTime(int alarmID, float time)
{
	SceneMan::SubtractAlarmTime(this, curTimes[alarmID], time);
	curTimes[alarmID] -= time;
}

Alarmable::~Alarmable()
{

}