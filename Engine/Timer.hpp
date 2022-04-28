#ifndef ENGINE_TIMER_HPP
#define ENGINE_TIMER_HPP

#include <SFML/System/Clock.hpp>
#include <functional>

class Timer
{
public:
	void Update(float dt);
	Timer(float time, std::function<void()> func);
private:
	float gonetime_;
	float endtime_;

	std::function<void()> func_;
};


#endif //ENGINE_TIMER_HPP