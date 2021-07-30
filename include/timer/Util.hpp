#pragma once

#ifndef LTIMER_VER
#define LTIMER_VER "0.1.1"
#endif

#include <string>

namespace tmr {
	std::string format(int x);
	int conv_tot_s(int ts, char u);
	long getCurrentSeconds();
}
