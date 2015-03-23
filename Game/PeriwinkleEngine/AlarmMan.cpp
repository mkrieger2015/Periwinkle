#include "AlarmMan.h"
#include "Alarmable.h"
#include "AlarmMarker.h"
#include "TimeMan.h"
#include <iostream>

void AlarmMan::Register(Alarmable* obj, int alarmID, float time)
{
	Deregister(obj,time);
	timelineMap.insert(std::pair<float, AlarmMarker*>(time, new AlarmMarker(obj,alarmID,time)));
}

void AlarmMan::Deregister(Alarmable* obj, float time)
{
	std::multimap<float, AlarmMarker*>::iterator fst;
	std::multimap<float, AlarmMarker*>::iterator lst;

	fst= timelineMap.equal_range(time).first;
	lst= timelineMap.equal_range(time).second;


	bool found;
	found= false;

	std::multimap<float, AlarmMarker*>::iterator it;
	it= fst;

	while (it != lst && found == false)
	{
		if((*it).second->GetCallbackPointer() == obj)
		{
			timelineMap.erase(it++);
			found= true;
		}
		else
		{
			it++;
		}		
	}
}

void AlarmMan::AddAlarmTime(Alarmable* obj, float time, float timeAdded)
{
	std::multimap<float, AlarmMarker*>::iterator fst;
	std::multimap<float, AlarmMarker*>::iterator lst;

	fst= timelineMap.equal_range(time).first;
	lst= timelineMap.equal_range(time).second;


	bool found;
	found= false;

	std::multimap<float, AlarmMarker*>::iterator it;
	it= fst;

	while (it != lst && found == false)
	{
		if((*it).second->GetCallbackPointer() == obj)
		{
			(*it).second->AddTime(timeAdded);
			found= true;
		}
		else
		{
			it++;
		}		
	}
}

void AlarmMan::SubtractAlarmTime(Alarmable* obj, float time, float timeSubtracted)
{
	std::multimap<float, AlarmMarker*>::iterator fst;
	std::multimap<float, AlarmMarker*>::iterator lst;

	fst= timelineMap.equal_range(time).first;
	lst= timelineMap.equal_range(time).second;


	bool found;
	found= false;

	std::multimap<float, AlarmMarker*>::iterator it;
	it= fst;

	while (it != lst && found == false)
	{
		if((*it).second->GetCallbackPointer() == obj)
		{
			(*it).second->SubtractTime(timeSubtracted);
			found= true;
		}
		else
		{
			it++;
		}		
	}
}



void AlarmMan::UpdateAlarms()
{
	bool ahead= false;
	std::multimap<float, AlarmMarker*>::iterator it;
	it= timelineMap.begin();
	while (it != timelineMap.end() && ahead == false)
	{
		if(((*it).second->GetAlarmTime()) <= TimeMan::GetTotalTime())
		{
			(*it).second->TriggerAlarm();
			timelineMap.erase(it++);
		}
		else
		{
			ahead= true;
		}
	}
}

AlarmMan::~AlarmMan()
{
	std::multimap<float, AlarmMarker*>::iterator it;
	it = timelineMap.begin();
	while (it != timelineMap.end())
	{
		delete (*it).second;
		it++;
	}
}