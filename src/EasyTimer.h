#pragma once
#include "Timer.h"
#include <unordered_map>
#include <string>
#include <mutex>

#ifndef EASY_TIMER_DISABLE
#include <iostream>
#define CREATE_TIMER(a,b) Timer timer(a,b)
#define END_TIMER(a)      timer.endMeasurement()
#define PRINT_TIMERS()    std::cout << EasyTimer::getEasyTimer()
#else
#define CREATE_TIMER(a,b)
#define END_TIMER(a)
#define PRINT_TIMERS()
#endif

class EasyTimer
{
private:
    static EasyTimer* instance;
    std::unordered_map<std::string, std::tuple<int, uint64_t, timeUnit> > timerMap_;
    std::mutex updateTimerMutex_;

public:
    static EasyTimer* getEasyTimer();
    void updateTimer(std::string& name, uint64_t elapsedTimeUs, timeUnit unit);
    friend std::ostream& operator<<(std::ostream& os, const EasyTimer* EasyTimer);
};

