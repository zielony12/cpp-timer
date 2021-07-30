#include <timer/Util.hpp>
#include <string>

std::string tmr::format(int x) {
	if(x < 10)
		return "0" + std::to_string(x);
	else
		return std::to_string(x);
}

int tmr::conv_tot_s(int ts, char u) {
	switch(u) {
		case 'h':
			return ts / 3600;
			break;
		case 'm':
			return (ts % 3600) / 60;
			break;
		case 's':
			return ts % 60;
			break;
		default:
			return 0;
	}
}
