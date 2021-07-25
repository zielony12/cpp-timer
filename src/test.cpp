#include <iostream>
#include <timer/Timer.hpp>

int main() {	
	int h, m, s;
	std::string c;
	std::cout << "Caption: ";
	std::cin >> c;
	std::cout << "Hours: ";
	std::cin >> h;
	std::cout << "Minutes: ";
	std::cin >> m;
	std::cout << "Seconds: ";
	std::cin >> s;
	Timer timer1(c, h, m, s);
	timer1.start();
	return 0;
}
