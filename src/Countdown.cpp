#include <timer/Countdown.hpp>
#include <timer/Util.hpp>
#include <iostream>
#include <unistd.h>

tmr::Countdown::Countdown(std::string c, int h, int m, int s) {
	caption = c;
	this->h = h;
	this->m = m;
	this->s = s;
	couldShowTime = true;
	couldShowCaptionAtEnd = true;
}

void tmr::Countdown::start() {
	int totalTime = h * 3600 + m *60 + s;
	for(int i = totalTime; i > 0; i --) {
		int h = tmr::conv_tot_s(i, 'h');
		int m = tmr::conv_tot_s(i, 'm');
		int s = tmr::conv_tot_s(i, 's');
		if(couldShowTime)
			std::cout << tmr::format(h) << " : " << tmr::format(m) << " : " << tmr::format(s) << std::endl;
		sleep(1); 
	}
	if(couldShowCaptionAtEnd) 
		std::cout << "Countdown Timer \"" << caption << "\" ended." << std::endl;
}
