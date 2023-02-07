![Easy Timer logo](https://github.com/alex-gilson/EasyTimer/blob/main/easy_timer_logo.png)

# Description

EasyTimer is a cross-platform C++ library to measure time. It's thread safe, an average of all executions of a timer in all threads is computed and can be output to the desired stream.

# Installation

First, set up your project for CMake. Then, in your project directory run

```bash
git submodule add https://github.com/alex-gilson/EasyTimer.git
```

Insert the following line to you CMakeLists.txt:

```cmake
add_subdirectory(EasyTimer)
```

and

```cmake
target_link_libraries(<your-project-name> PUBLIC EasyTimer)
```

# Usage

Simply add the EasyTimer header file to your code:

```C++
#include "EasyTimer.h"
```

To create a timer use the following sintax:

```C++
{
  Timer timer1("Timer1", timeUnit::MICROSECONDS);
  doSomething();
}
Timer timer2("Timer2", timeUnit::MILISECONDS);
Timer timer3("Timer3", timeUnit::SECONDS);
{
  Timer timer4("Timer1", timeUnit::MICROSECONDS);
  doSomething();
}
timer3.endMeasurement();
```

When the timers go out of scope, the measurement will be finalized. Optionally ```endMeasurement()``` can be used. For Timer1, the average of timer1 and timer4 will be taken.

To print the results. Add the following line to your code:

```C++
std::cout << EasyTimer::getEasyTimer() << std::endl;
```

# Example

```C++
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
  int numThreads = 8;
  std::vector<std::thread> threads;
  for (int i = 0; i < numThreads; i++)
  {
    // Even and odd threads share their respective timer name
    std::string timerName = "thread_timer_" + std::to_string( (i%2) + 1 );
    threads.push_back(std::thread{runThreadTask, timerName, 100});
  }
  for (auto& thread : threads)
  {
    thread.join();
  }
  std::cout << EasyTimer::getEasyTimer() << std::endl;
  return 0;
}
```

The output would be like this:

```
Name,Time,Count
thread_timer_2,3us,400
thread_timer_1,7us,400
```
