#include <timer/Countdown.hpp>
#include <iostream>
#include <unistd.h>

using namespace tmr;

Countdown::Countdown(std::string c, int h, int m, int s) {
	caption = c;
	this->h = h;
	this->m = m;
	this->s = s;
	couldShowTime = true;
}

std::string Countdown::format(int x) {
	if(x < 10)
		return "0" + std::to_string(x);
	else
		return std::to_string(x);
}

void Countdown::start() {
	int totalTime = h * 3600 + m * 60 + s;
	for(int i = totalTime; i > 0; i --) {
		int h = i / 3600;
		int m = (i % 3600) / 60;
		int s = i % 60;
		if(couldShowTime)
			std::cout << Countdown::format(h) << " : " << Countdown::format(m) << " : " << Countdown::format(s) << std::endl;
		sleep(1); 
	}
	std::cout << "Countdown Timer ”" << caption << "” ended." << std::endl;
}
