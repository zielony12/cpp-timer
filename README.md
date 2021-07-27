# cpp-timer
Simple timer written in C++
# build from source
`git clone https://github.com/zielony12/cpp-timer.git`

`cd cpp-timer`

`make`
or for arch based operating systems: `makepkg -si`
# usage
Sample main file:

```cpp
#include <Timer.hpp> // include the timer library

int main() {
	tmr::Timer timer1("Timer 1", 0, 1, 30); // new instance of Timer with caption "Timer 1", and time 1 min, 30 secs
	timer1.start(); // run the timer1
	return 0;
}

Compiling: `g++ -c main.cpp`
Linking: `g++ main.o -o timer-app -ltimer`
