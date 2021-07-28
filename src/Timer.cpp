#include <timer/Timer.hpp>
#include <string>

std::string tmr::format(int x) {
	if(x < 10)
		return "0" + std::to_string(x);
	else
		return std::to_string(x);
}
