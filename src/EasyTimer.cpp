#include "EasyTimer.h"
#include <iostream>

EasyTimer* EasyTimer::instance = 0;
std::mutex getEasyTimerMutex_;

EasyTimer* EasyTimer::getEasyTimer()
{
	std::lock_guard<std::mutex> getEasyTimerLock(getEasyTimerMutex_);
	if (!instance) {
		instance = new EasyTimer;
	}
	return instance;
}

void EasyTimer::updateTimer(std::string& name, uint64_t elapsedTimeUs, timeUnit unit)
{
	std::lock_guard<std::mutex> updateTimerLock(updateTimerMutex_);
	if (timerMap_.find(name) == timerMap_.end()) {
		timerMap_[name] = std::tuple<int, uint64_t, timeUnit>(0, 0, unit);
	}
	std::get<0>(timerMap_[name])++;
	std::get<1>(timerMap_[name]) += elapsedTimeUs;
}

std::ostream& operator<<(std::ostream& os, const EasyTimer* EasyTimer)
{
	os << "Name,Time,Count\n";
	for (auto& [timerName, timingData] : EasyTimer->timerMap_)
	{
		os << timerName << "," << std::to_string(std::get<1>(timingData) / std::get<0>(timingData));
		switch (std::get<2>(timingData))
		{
		case timeUnit::MICROSECONDS:
		{
			os << "us,";
			break;
		}
		case timeUnit::MILISECONDS:
		{
			os << "ms,";
			break;
		}
		case timeUnit::SECONDS:
		{
			os << "s,";
			break;
		}
		}
		os << std::get<0>(timingData) << "\n";
	}
	return os;
}
