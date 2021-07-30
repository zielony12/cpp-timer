#include <timer/Stopwatch.hpp>
#include <timer/Util.hpp>
#include <iostream>
#include <unistd.h>

tmr::Stopwatch::Stopwatch(std::string c) {
	caption = c;
	couldShowTime = true;
}

void tmr::Stopwatch::start() {
	running = true;
	spentTime = 0;
	for(; running; spentTime ++) {
		int h = tmr::conv_tot_s(spentTime, 'h');
		int m = tmr::conv_tot_s(spentTime, 'm');
		int s = tmr::conv_tot_s(spentTime, 's');
		if(couldShowTime)
			std::cout << tmr::format(h) << " : " << tmr::format(m) << " : " << tmr::format(s) << std::endl;
		sleep(1);
	}
	
}

void tmr::Stopwatch::stop() {
	running = false;
}

int tmr::Stopwatch::getSpentTime() {
	return spentTime;
}
