#include <timer/Countdown.hpp> // include Countdown class

int main() {
	tmr::Countdown c1("Countdown timer 1", 0, 0, 5); // create and set the timer to 5 seconds
	c1.couldShowTime = false; // default true
	c1.start(); // start the countdown timer
	return 0;
}
