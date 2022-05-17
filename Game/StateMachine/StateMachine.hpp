#ifndef GAME_STATEMACHINE_STATEMACHINE_HPP
#define GAME_STATEMACHINE_STATEMACHINE_HPP

#include <queue>
#include <SFML/Graphics.hpp>

class State;

class StateMachine
{
public:
	StateMachine(sf::RenderWindow& window, const float& dt, const float& fixdt);
	~StateMachine();

	void PushState(State* state);

	void FixedUpdate();
	void Update();
	void Render();

	sf::RenderWindow& window_;
	const float& dt_;
	const float& fixdt_;
private:

	sf::Sprite sprite_;
	sf::RenderTexture frame_;
	std::queue<State*> states_;
};

class State
{
public:
	State(StateMachine& machine);
	virtual ~State();

	virtual void FixedUpdate() = 0;
	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget& target) = 0;

	bool IsRunning() const;
protected:
	StateMachine& machine_;
	sf::RenderWindow& window_;

	const float& dt_;
	const float& fixdt_;
	bool isRun = true;
};

#endif //GAME_STATEMACHINE_STATEMACHINE_HPP