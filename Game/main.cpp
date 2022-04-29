#include <SFML/Graphics.hpp>
#include "Game.hpp"

static const float kStepT = 0.01f;

int main()
{
	sf::Clock dClock;
	sf::Clock fixdClock;

	float dt = 0f;
	float fixdt = 0f;
	float gonet = 0f;

	Game game(dt, fixdt);

	dClock.restart();
	fixdClock.restart();

	while(game.isRunning())
	{
		gonet += dt;
		while(gonet > kStepT)
		{
			fixdt = fixdClock.restart().asSeconds();
			if(fixdt > kStepT*5f)
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