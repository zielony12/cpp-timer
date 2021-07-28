#include <timer/Countdown.hpp>
#include <timer/Stopwatch.hpp>

int main() {
	tmr::Countdown c1("Countdown timer 1", 0, 0, 5);
	c1.start();
	tmr::Stopwatch s1("Stopwatch timer 1");
	s1.start();
	return 0;
}
