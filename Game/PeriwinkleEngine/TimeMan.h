#ifndef _TimeMan
#define _TimeMan

#include "Azul.h"

///
///\class	TimeMan
///\ingroup Time
///\brief	Singleton time manager. Used primarily by AlarmMan, but can also be used for other purposes. Returns frame time or total run time.
///
///\author	Max Krieger
///\date	3/5/2015
///
class TimeMan
{
private: 


	///\brief	The self pointer for singleton accessor.
	static TimeMan *self;

	///
	///\fn	TimeMan::TimeMan()
	///
	///\brief	Default constructor (empty, singleton)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	TimeMan(){ };

	///
	///\fn	TimeMan::TimeMan(const TimeMan&)
	///
	///\brief	Copy constructor (empty, singleton)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	TimeMan(const TimeMan&){ };

	///
	///\fn	TimeMan& TimeMan::operator= (const TimeMan&)
	///
	///\brief	Assignment operator for shallow copy (empty, singleton)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	TimeMan& operator= (const TimeMan&){ };

	///
	///\fn	TimeMan::~TimeMan();
	///
	///\brief	Destructor (empty, singleton)
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	~TimeMan();

	///
	///\fn	static TimeMan& TimeMan::Instance()
	///
	///\brief	Singleton instance accessor. If the TimeMan hasn't been created, create it. If it has, return its instance. Accessor for all public static methods.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\return	A TimeMan&amp;
	///
	static TimeMan& Instance()
	{
		if (!self)
			self= new TimeMan();
		return *self;
	};


	///\brief	The frame time.
	StopWatch frameTime;


	///\brief	The total time.
	StopWatch totalTime;

public: 

	///
	///\fn	static void TimeMan::Initialize();
	///
	///\brief	Things to do on initialization.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void Initialize();

	///
	///\fn	static float TimeMan::GetFrameTime();
	///
	///\brief	Returns current frame time (Frame rate).
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\return	The frame time.
	///
	static float GetFrameTime();

	///
	///\fn	static float TimeMan::GetTotalTime();
	///
	///\brief	Returns current total runtime.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	///\return	The total time.
	///
	static float GetTotalTime();

	///
	///\fn	static void TimeMan::Update();
	///
	///\brief	Updates times.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void Update();

	///
	///\fn	static void TimeMan::Delete();
	///
	///\brief	Deletes the self. To be used on shutdown.
	///
	///\author	Max Krieger
	///\date	3/5/2015
	///
	static void Delete();

};

#endif 