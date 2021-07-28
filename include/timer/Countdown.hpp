#pragma once

#include <string>

namespace tmr {
	class Countdown {
		public:
			Countdown(std::string c, int h, int m, int s);
			int h, m, s;
			bool couldShowTime, couldShowCaptionAtEnd;
			std::string caption;
			void start(), showTime();
	};
}
