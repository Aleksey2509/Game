#include "Timer.hpp"

void Timer::Update(float dt)
{
	gonetime_ += dt;
	while(gonetime_ > endtime_)
	{
		func_();
		gonetime_ -= endtime_;
	}
}

void Timer::SetFunction(float time, std::function<void()> func)
{
	endtime_ = time;
	func_ = func;
}

void Timer::SetTime(float time)
{
	endtime_ = time;
}

float Timer::GetTime() const
{
	return endtime_;
}