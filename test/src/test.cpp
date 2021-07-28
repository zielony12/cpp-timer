#include <timer/Countdown.hpp>	// include Countdown class
#include <timer/Stopwatch.hpp>	// include Stopwatch class

int main() {
	tmr::Countdown c1("Countdown timer 1", 0, 0, 5); // create and set the timer to 5 seconds
	c1.start(); // start the countdown timer
	tmr::Stopwatch s1("Stopwatch timer 1"); // useless without threads
	s1.start(); // start the stopwatch timer
	return 0;
}
