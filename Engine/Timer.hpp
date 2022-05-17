#ifndef ENGINE_TIMER_HPP
#define ENGINE_TIMER_HPP

#include <SFML/System/Clock.hpp>
#include <functional>

class Timer
{
public:
	void Update(float dt);
	void SetFunction(float time, std::function<void()> func);
	void SetTime(float time);
	float GetTime() const;
private:
	float gonetime_ = 0.f;
	float endtime_ = 10e5;

	std::function<void()> func_;
};


#endif //ENGINE_TIMER_HPP