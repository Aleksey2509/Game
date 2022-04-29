#include "StateMachine.hpp"

StateMachine::StateMachine(sf::RenderWindow& window, float dt, float fixdt) :
	window_(window), dt_(dt), fixdt_(fixdt)
{
	auto params = window_.getSize();
	frame_.create(params.x, params.y);
}

StateMachine::~StateMachine()
{
	while(!states_.empty())
	{
		delete states_.top();
		states_.pop();
	}
}

void StateMachine::PushState(State* state)
{
	states_.push(state);
}

void StateMachine::FixedUpdate()
{
	if(!states_.empty())
	{
		states_.top()->FixedUpdate();
	}
}

void StateMachine::Update()
{
	if(!states_.empty())
	{
		states_.top()->Update();
		if(!states_.top()->IsRunning())
		{
			delete states_.top();
			states_.pop();
		}
	}
	else
	{
		window_.close();
	}
}

void StateMachine::Render()
{
	frame_.clear();

	if(!states_.empty())
	{
		states_.top()->Render(frame_);
	}
	frame_.display();
	sprite_.setTexture(frame_.getTexture());
	window_.draw(sprite_);
}

State::State(StateMachine& machine) :
machine_(machine), window_(machine.window_), dt_(machine.dt_), fixdt_(machine.fixdt_) {}

State::~State() {}

bool State::IsRunning() const
{
	return isRun;
}