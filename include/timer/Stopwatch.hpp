#pragma once

#include <string>

namespace tmr {
	class Stopwatch {
		public:
			Stopwatch(std::string c);
			int h, m, s;
			std::string caption;
			bool running, couldShowTime;
			void start(), stop();
	};
}
