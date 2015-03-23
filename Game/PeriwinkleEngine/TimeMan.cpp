#include "TimeMan.h"
#include <iostream>

TimeMan* TimeMan::self = NULL;

void TimeMan::Initialize()
{
	StopWatch::initStopWatch();
	Instance().frameTime.tic();
	Instance().totalTime.tic();
}

float TimeMan::GetFrameTime()
{
	return Instance().frameTime.timeInSeconds();
}

float TimeMan::GetTotalTime()
{
	return Instance().totalTime.timeInSeconds();
}

void TimeMan::Update()
{
	Instance().frameTime.toc();
	Instance().frameTime.tic();
	Instance().totalTime.toc();
}

void TimeMan::Delete()
{
	delete self;
}

TimeMan::~TimeMan()
{

}