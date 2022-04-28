#include "Timer.hpp"

Timer::Timer(float time, std::function<void()> func)
{
	endtime_ = time;
	func_ = func;
}

void Timer::Update(float dt)
{
	gonetime_ += dt;
	while(gonetime_ > endtime_)
	{
		func_();
		gonetime_ -= endtime_;
	}
}