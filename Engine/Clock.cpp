/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "Clock.h"



Clock::Clock()
{
}


Clock::~Clock()
{
}

void Clock::startClock()
{
	Clock::startTime = clock();
}

void Clock::updateClock()
{
	Clock::millisecondPassed = (clock() - Clock::startTime);
}

double Clock::getMilliseconds()
{
	return Clock::millisecondPassed;
}

double Clock::getSeconds()
{
	return Clock::millisecondPassed / CLOCKS_PER_SEC;
}

void Clock::resetClock()
{
	Clock::startClock();
}

void Clock::setDelay(double milliseconds)
{
	millisecondToDelay = milliseconds;
}

void Clock::setDelayInSeconds(int seconds)
{
	Clock::setDelay((double) seconds * 1000);
}

bool Clock::alarm()
{
	return (Clock::millisecondPassed >= millisecondToDelay);
}
