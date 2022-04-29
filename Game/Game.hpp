#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include "../Engine/CheckKey.hpp"

class Game
{
public:
	Game(float dt, float fixdt);
	~Game();

	void Update();
	void FixedUpdate();
	void Render();

	bool IsRunning() const;
private:
	sf::RenderWindow window_;
	sf::Event event_;

	float dt_;
	float fixdt_;
	KeyCheck keyCheck_;

	void HandleEvents();
};

#endif //GAME_GAME_HPP