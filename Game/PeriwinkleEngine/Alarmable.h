#ifndef _Alarmable
#define _Alarmable

#include "Azul.h"

///
///\class	Alarmable
///\ingroup Alarms
///\brief	Parent class for all objects with alarm functionality.
///
///\author	Max Krieger
///\date	3/4/2015
///

class Alarmable
{
private:

	///\brief	Number of possible alarms set, currently three: Alarm 0, Alarm 1, and Alarm 2.
	float curTimes[3];

public:

	///
	///\fn	virtual Alarmable::~Alarmable();
	///
	///\brief	Destructor.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual ~Alarmable();

	///
	///\fn	virtual void Alarmable::Alarm0();
	///
	///\brief	Alarm 0 event. To be user-defined.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void Alarm0();

	///
	///\fn	virtual void Alarmable::Alarm1();
	///
	///\brief	Alarm 1 event. To be user-defined.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void Alarm1();

	///
	///\fn	virtual void Alarmable::Alarm2();
	///
	///\brief	Alarm 2 event. To be user-defined.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	virtual void Alarm2();

	///
	///\fn	void Alarmable::Dispatch(int alarmID);
	///
	///\brief	The gatekeeper function for executing an alarm event. Called by an AlarmMarker after it triggers; the AlarmMarker passes in the alarm event to be called (0, 1, or 2).
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	alarmID	Which alarm is to be triggered (0, 1, or 2).
	///
	void Dispatch(int alarmID);

	///
	///\fn	void Alarmable::SetAlarm(int alarmID, float time);
	///
	///\brief	Wrapper for registering an AlarmMarker with a callback to this object to the timeline.
	///
	///\author	Max Krieger
	///\date	3/4/2015
	///
	///\param	alarmID	Which alarm is to be triggered (0, 1, or 2).
	///\param	time   	Amount of time before alarm goes off.
	///
	void SetAlarm(int alarmID, float time);

	///
	///\fn	void Alarmable::ClearAlarm(int alarmID);
	///
	///\brief	Wrapper for deregistering an AlarmMarket with a callback to this object from the timeline.
	///
	///\author	Max Krieger
	///\date	3/13/2015
	///
	///\param	alarmID	Identifier for the alarm.
	///
	void ClearAlarm(int alarmID);

	///
	///\fn	void Alarmable::AddTime(int alarmID, float time);
	///
	///\brief	Adds time to the alarm represented by alarmID.
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	///\param	alarmID	Identifier for the alarm.
	///\param	time   	The time.
	///
	void AddTime(int alarmID, float time);

	///
	///\fn	void Alarmable::SubtractTime(int alarmID, float time);
	///
	///\brief	Subtracts time to the alarm represented by alarmID.
	///
	///\author	Max Krieger
	///\date	3/14/2015
	///
	///\param	alarmID	Identifier for the alarm.
	///\param	time   	The time.
	///
	void SubtractTime(int alarmID, float time);
};

#endif 