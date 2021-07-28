# cpp-timer
Simple timer written in C++
# build from source
`git clone https://github.com/zielony12/cpp-timer.git`

`cd cpp-timer`

`make`
or for arch based operating systems: `makepkg -si`
# usage
Sample:

```cpp
#include <timer/Countdown.hpp>	// include the timer library

int main() {
	tmr::Countdown ct1("Countdown Timer 1", 0, 1, 30); // new instance of Countdown with caption "Countdown Timer 1", and time 1 min, 30 secs
	ct1.couldShowTime = false; // disable displaying the time. Enabled by default
	ct1.start(); // run the ct1
	return 0;
}
```

Compiling: `g++ -c main.cpp`;
Linking: `g++ main.o -o timer-app -ltimer`
