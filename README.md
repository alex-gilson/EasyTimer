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

An example output is like this:

```
Name,Time,Count
timer3,134s,3
thread_timer_4,3us,100
timer2,0ms,1
timer1,12us,3
thread_timer_2,2us,100
timer4,0ms,1
thread_timer_1,2us,100
thread_timer_3,5us,100
thread_timer_5,2us,100
thread_timer_6,2us,100
thread_timer_7,5us,100
thread_timer_8,10us,100
```
