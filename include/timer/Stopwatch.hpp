#pragma once

#include <string>

namespace tmr {
	class Stopwatch {
		private:
			bool running;
			int spentTime;
		public:
			Stopwatch(std::string c);
			int h, m, s, getSpentTime();
			std::string caption;
			bool couldShowTime, isRunning();
			void start(), stop();
	};
}
