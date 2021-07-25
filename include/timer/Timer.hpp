#pragma once

#include <string>

class Timer {
	public:
		Timer(std::string c, int h, int m, int s);
		int h, m, s;
		std::string format(int x),  caption;
		void start();
};
