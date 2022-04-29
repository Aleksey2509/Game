#include <SFML/Graphics.hpp>
#include "Game.hpp"

static const float kStepT = 0.01f;
static const unsigned int kWidth = 1000;
static const unsigned int kHeight = 1000;

int main()
{
	sf::Clock dClock;
	sf::Clock fixdClock;

	float dt = 0.f;
	float fixdt = 0.f;
	float gonet = 0.f;


	Game game(dt, fixdt, kWidth, kHeight);

	dClock.restart();
	fixdClock.restart();

	while(game.IsRunning())
	{
		gonet += dt;
		while(gonet > kStepT)
		{
			fixdt = fixdClock.restart().asSeconds();
			if(fixdt > kStepT*5.f)
			{
				fixdt = kStepT;
			}
			game.FixedUpdate();
			gonet -= kStepT;
		}
		game.Update();
		game.Render();
		dt = dClock.restart().asSeconds();
	}

	return 0;
}