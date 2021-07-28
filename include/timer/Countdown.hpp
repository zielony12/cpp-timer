#pragma once

#include <string>

namespace tmr {
	class Countdown {
		public:
			Countdown(std::string c, int h, int m, int s);
			int h, m, s;
			bool couldShowTime;
			std::string format(int x),  caption;
			void start(), showTime();
	};
}
