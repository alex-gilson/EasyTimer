#pragma once
#include <chrono>
#include <string>

using highResTime = decltype(std::chrono::high_resolution_clock::now());

enum class timeUnit
{
	MICROSECONDS,
	MILISECONDS,
	SECONDS
};

class Timer
{
	std::chrono::time_point< std::chrono::high_resolution_clock> initTime;
	std::string name_;
	highResTime initTime_;
	timeUnit unit_;
public:
	Timer(std::string name, timeUnit unit);
	~Timer();
	void endMeasurement();
	friend std::ostream& operator<<(std::ostream& os, const Timer& timer);
};

