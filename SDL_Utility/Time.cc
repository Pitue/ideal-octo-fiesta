#include "Time.h"

mh::Time::Time(): milliseconds_{0} {}
mh::Time::Time(uint_fast64_t milliseconds): milliseconds_{milliseconds} {}
double mh::Time::AsSeconds(void) {
	return static_cast<double>(milliseconds_) / 1000.f;
}

mh::Clock::Clock() : time_{ 0 } {}
mh::Time mh::Clock::GetElapsedTime(void) {
	return mh::Time(SDL_GetTicks() - time_);
}
mh::Time mh::Clock::Restart(void) {
	mh::Time temp = GetElapsedTime();
	time_ = SDL_GetTicks();
	return temp;
}