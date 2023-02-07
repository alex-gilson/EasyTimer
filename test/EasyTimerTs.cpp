#include "EasyTimer.h"
#include <iostream>
#include <thread>
#include <vector>

void runThreadTask(std::string timerName, int numLoops)
{
	for (int i = 0; i < numLoops; i++)
	{
		Timer timer(timerName, timeUnit::MICROSECONDS);
		int sum = 0;
		for (int n = 0; n < 1000; n++)
		{
			sum++;
		}
	}
}

int main()
{
	// Test automatic deletion of timer and print
	{
		{
			Timer timer1("timer1", timeUnit::MICROSECONDS);
			Timer timer2("timer2", timeUnit::MILISECONDS);
			Timer timer3("timer3", timeUnit::SECONDS);
			timer3.endMeasurement();
		}
		std::cout << EasyTimer::getEasyTimer() << std::endl;
	}
	// Test printing of individual timer
	{
		Timer timer3("timer3", timeUnit::MICROSECONDS);
		std::cout << timer3 << std::endl;
		Timer timer4("timer4", timeUnit::MILISECONDS);
		std::cout << timer3 << std::endl;
		std::cout << timer4 << std::endl;
	}
	// Test that average of two timers is taken
	{
		{
			Timer timer1("timer1", timeUnit::MICROSECONDS);
		}
		{
			Timer timer1("timer1", timeUnit::MICROSECONDS);
		}
		std::cout << EasyTimer::getEasyTimer() << std::endl;
	}
	// Test multithreading
	{
		int numThreads = 8;
		std::vector<std::thread> threads;
		for (int i = 0; i < numThreads; i++)
		{
			std::string timerName = "thread_timer_" + std::to_string( i + 1 );
			threads.push_back(std::thread{runThreadTask, timerName, 100});
		}
		for (auto& thread : threads)
		{
			thread.join();
		}
		std::cout << EasyTimer::getEasyTimer() << std::endl;
	}
	return 0;
}