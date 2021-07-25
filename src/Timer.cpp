#include <timer/Timer.hpp>
#include <iostream>
#include <unistd.h>

Timer::Timer(std::string c, int h, int m, int s) {
	caption = c;
	this->h = h;
	this->m = m;
	this->s = s;
}

std::string Timer::format(int x) {
	if(x < 10)
		return "0" + std::to_string(x);
	else
		return std::to_string(x);
}

void Timer::start() {
	int totalTime = h * 3600 + m * 60 + s;
	for(int i = totalTime; i > 0; i --) {
		int h = i / 3600;
		int m = (i % 3600) / 60;
		int s = i % 60;
		std::cout << Timer::format(h) << " : " << Timer::format(m) << " : " << Timer::format(s) << std::endl;
		sleep(1); 
	}
	std::cout << "Timer ”" << caption << "” ended." << std::endl;
}
