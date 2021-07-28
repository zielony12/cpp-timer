#include <timer/Stopwatch.hpp>
#include <timer/Timer.hpp>
#include <iostream>
#include <unistd.h>

tmr::Stopwatch::Stopwatch(std::string c) {
	caption = c;
	couldShowTime = true;
}

void tmr::Stopwatch::start() {
	running = true;
	int spentTime = 0;
	for(; running; spentTime ++) {
		int h = spentTime / 3600;
		int m = (spentTime % 3600) / 60;
		int s = spentTime % 60;
		if(couldShowTime)
			std::cout << tmr::format(h) << " : " << tmr::format(m) << " : " << tmr::format(s) << std::endl;
		sleep(1);
	}
	
}

void tmr::Stopwatch::stop() {
	running = false;
}
