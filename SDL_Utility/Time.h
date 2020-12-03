#pragma once
#include <stdint.h>
#include <SDL.h>
namespace mh {
	class Time {
		uint_fast64_t milliseconds_;
	public:
		Time();
		Time(uint_fast64_t milliseconds);
		double AsSeconds(void);
		template <typename T> T AsMilliseconds(void) {
			return static_cast<T> (milliseconds_);
		}
	};

	class Clock {
		uint_fast32_t time_;
	public:
		Clock();
		Time GetElapsedTime(void);
		Time Restart(void);
	};
}

