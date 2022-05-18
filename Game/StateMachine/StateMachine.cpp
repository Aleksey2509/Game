#include "StateMachine.hpp"

StateMachine::StateMachine(sf::RenderWindow& window, const float& dt, const float& fixdt) :
	window_(window), dt_(dt), fixdt_(fixdt)
{
	auto params = window_.getSize();
	frame_.create(params.x, params.y);
}

StateMachine::~StateMachine()
{
	while(!states_.empty())
	{
		delete states_.front();
		states_.pop_front();
	}
}

void StateMachine::PushBackState(State* state)
{
    states_.push_back(state);
}

void StateMachine::PushFrontState(State* state)
{
    states_.push_front(state);
}

void StateMachine::PopBackState()
{
    delete states_.back();
    states_.pop_back();
}

void StateMachine::FixedUpdate()
{
	if(!states_.empty())
	{
		states_.front()->FixedUpdate();
	}
}

void StateMachine::Update()
{
	if(!states_.empty())
	{
		states_.front()->Update();
		if(!states_.front()->IsRunning())
		{
			delete states_.front();
			states_.pop_front();
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
		states_.front()->Render(frame_);
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