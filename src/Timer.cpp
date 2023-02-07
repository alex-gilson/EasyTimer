#include "Timer.h"
#include "EasyTimer.h"
#include <iostream>


Timer::Timer(std::string name, timeUnit unit)
	: name_(name), unit_(unit)
{
	initTime_ = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	endMeasurement();
}
void Timer::endMeasurement()
{
	highResTime finalTime = std::chrono::high_resolution_clock::now();
	switch (unit_)
	{
	case timeUnit::MICROSECONDS:
	{
		auto exTime = std::chrono::duration_cast<std::chrono::microseconds>(finalTime - initTime_);
		EasyTimer::getEasyTimer()->updateTimer(name_, exTime.count(), unit_);
		break;
	}
	case timeUnit::MILISECONDS:
	{
		auto exTime = std::chrono::duration_cast<std::chrono::milliseconds>(finalTime - initTime_);
		EasyTimer::getEasyTimer()->updateTimer(name_, exTime.count(), unit_);
		break;
	}
	case timeUnit::SECONDS:
	{
		auto exTime = std::chrono::duration_cast<std::chrono::seconds>(finalTime - initTime_);
		EasyTimer::getEasyTimer()->updateTimer(name_, exTime.count(), unit_);
		break;
	}
	}
}

std::ostream& operator<<(std::ostream& os, const Timer& timer)
{
	highResTime finalTime = std::chrono::high_resolution_clock::now();
	switch (timer.unit_)
	{
	case timeUnit::MICROSECONDS:
	{
		auto exTime = std::chrono::duration_cast<std::chrono::microseconds>(finalTime - timer.initTime_);
		os << exTime.count() << "us";
		break;
	}
	case timeUnit::MILISECONDS:
	{
		auto exTime = std::chrono::duration_cast<std::chrono::milliseconds>(finalTime - timer.initTime_);
		os << exTime.count() << "ms";
		break;
	}
	case timeUnit::SECONDS:
	{
		auto exTime = std::chrono::duration_cast<std::chrono::seconds>(finalTime - timer.initTime_);
		os << exTime.count() << "s";
		break;
	}
	}
	return os;
}

