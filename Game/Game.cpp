#include "Game.hpp"

Game::Game(float dt, float fixdt, int winWidth, int winHeight) : dt_(dt), fixdt_(fixdt), keyCheck_()
{
	sf::VideoMode win(winWidth, winHeight);
	window_.create(win, "Bulletoid");
	window_.setFramerateLimit(288);
	machine_ = new StateMachine(window_, dt, fixdt);
	machine_->PushState(new InGame(*machine_));
}

Game::~Game()
{
	delete machine_;
}

void Game::Update()
{
	HandleEvents();
	machine_->Update();
	keyCheck_.Update();
}

void Game::FixedUpdate()
{
	machine_->FixedUpdate();
}

void Game::Render()
{
	window_.clear();
	machine_.Render();
	window_.display();
}

bool Game::IsRunning()
{
	return window_.isOpen();
}

void Game::HandleEvents()
{
	while(window_.pollEvent(event_))
	{
		switch(event_.type)
		{
			case sf::Event::Closed :
				window_.close();
				break;
		}
	}
}