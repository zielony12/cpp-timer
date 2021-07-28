#include <timer/Countdown.hpp>
#include <timer/Timer.hpp>
#include <iostream>
#include <unistd.h>

using namespace tmr;

Countdown::Countdown(std::string c, int h, int m, int s) {
	caption = c;
	this->h = h;
	this->m = m;
	this->s = s;
	couldShowTime = true;
	couldShowCaptionAtEnd = true;
}

void Countdown::start() {
	int totalTime = h * 3600 + m * 60 + s;
	for(int i = totalTime; i > 0; i --) {
		int h = i / 3600;
		int m = (i % 3600) / 60;
		int s = i % 60;
		if(couldShowTime)
			std::cout << tmr::format(h) << " : " << tmr::format(m) << " : " << tmr::format(s) << std::endl;
		sleep(1); 
	}
	if(couldShowCaptionAtEnd) 
		std::cout << "Countdown Timer \"" << caption << "\" ended." << std::endl;
}
