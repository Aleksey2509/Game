#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include "CheckKey.hpp"
#include "StateMachine/StateMachine.hpp"
#include "StateMachine/States/InGame.hpp"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(const float& dt, const float& fixdt, unsigned int winWidth, unsigned int winHeight);
	~Game();

	void Update();
	void FixedUpdate();
	void Render();

	bool IsRunning() const;
private:
	StateMachine* machine_;
	sf::RenderWindow window_;
	sf::Event event_;

	const float& dt_;
	const float& fixdt_;

	void HandleEvents();
};

#endif //GAME_GAME_HPP