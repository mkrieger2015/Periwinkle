#ifndef _AlarmMan
#define _AlarmMan

#include "Azul.h"
#include <map>

class Alarmable;
class AlarmMarker;

///
///\class	AlarmMan
///\ingroup Alarms
///\brief	Per-scene manager for alarm markers.
///
///\author	Max Krieger
///\date	3/4/2015
///

class AlarmMan
{
private:


	///\brief	The timeline map.
	std::multimap<float, AlarmMarker*> timelineMap;
public:

	///
	///\fn	void AlarmMan::Register(Alarmable* obj, int alarmID, float time);
	///
	///\brief	Registers an AlarmMarker to the timeline.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param   obj         The Alarmable callback for the AlarmMarker. Used to make AlarmMarker.
	///\param	alarmID	   	Identifier for the alarm. Used to make AlarmMarker.
	///\param	time	   	The time to register the AlarmMarker at. Used to make AlarmMarker.
	///
	void Register(Alarmable* obj, int alarmID, float time);

	///
	///\fn	void AlarmMan::Deregister(Alarmable* obj, float time);
	///
	///\brief	Deregisters an AlarmMarker with data matching the input parameters from the timeline map.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	time	   	The time.
	///
	void Deregister(Alarmable* obj, float time);

	///
	///\fn	void AlarmMan::AddAlarmTime(Alarmable* obj, float time, float timeAdded);
	///
	///\brief	Adds time to an alarm with matching time and callback to obj.
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	///\param [in,out]	obj	If non-null, the object.
	///\param	time	   	The time.
	///\param	timeAdded  	The time added.
	///
	void AddAlarmTime(Alarmable* obj, float time, float timeAdded);

	///
	///\fn	void AlarmMan::SubtractAlarmTime(Alarmable *obj, float time, float timeSubtracted);
	///
	///\brief	Subtracts time from an alarm with matching time and callback to obj.
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	///\param [in,out]	obj   	If non-null, the object.
	///\param	time		  	The time.
	///\param	timeSubtracted	The time subtracted.
	///
	void SubtractAlarmTime(Alarmable *obj, float time, float timeSubtracted);

	///
	///\fn	void AlarmMan::UpdateAlarms();
	///
	///\brief	Goes through the timeline map and checks which alarms to activate.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	void UpdateAlarms();

	///
	///\fn	AlarmMan::~AlarmMan();
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	~AlarmMan();
};

#endif