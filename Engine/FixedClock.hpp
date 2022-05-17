#ifndef ENGINE_FIXEDCLOCK_HPP
#define ENGINE_FIXEDCLOCK_HPP

#include <SFML/System/Clock.hpp>

class FixedClock
{
public:
	sf::Time GetTime()
	{
		if(flag_)
		{
			clock_.restart();
			flag_ = false;
		}
		return clock_.getElapsedTime();
	}
	void restart()
	{
		clock_.restart();
		flag_ = true;
	}
private:
	sf::Clock clock_;
	bool flag_ = true;
};


#endif //ENGINE_FIXEDCLOCK_HPP