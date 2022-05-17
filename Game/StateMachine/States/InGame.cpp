#include "InGame.hpp"

static const int kWidth = 1000;
static const int kHeight = 1000;

InGame::InGame(StateMachine& machine) : State(machine)
{
	InitPlatforms();
	InitAssets();
	InitSprites();
	InitEntities();
}

InGame::~InGame()
{
	delete player_;
	delete heart_;
}

void InGame::FixedUpdate()
{
	if(player_->IsAlive())
	{
		FixedUpdateEntities();
	}
}

void InGame::Update()
{
	if(player_->IsAlive())
	{
		UpdateEntities();
	}
}

void InGame::Render(sf::RenderTarget& target)
{
	target.draw(sprites_["background"]);
	target.draw(*player_);
	if(heart_)
	{
		target.draw(*heart_);
	}
}

void InGame::SpawnHeart()
{
	if(heartSpawnClock_.getElapsedTime().asSeconds() > 10.f)
	{
		heart_ = new Heart(dt_, fixdt_, &textureManager_.Get("heart"));
	}
}

void InGame::InitAssets()
{
	textureManager_.Load("player", "../Images/player.png");
	textureManager_.Load("background", "../Images/map.png");
	textureManager_.Load("heart", "../Images/heart.png");
	textureManager_.Load("healthbar", "../Images/healthbar.png");
}

void InGame::InitPlatforms()
{
	platforms_.push_back(Platform(sf::Vector2f(kWidth/2.f, 940.f), sf::Vector2f(1100.f, 100.f)));
	platforms_.push_back(Platform(sf::Vector2f(140.f, 755.f), sf::Vector2f(220.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(500.f, 755.f), sf::Vector2f(260.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(810.f, 755.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(200.f, 595.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(730.f, 565.f), sf::Vector2f(180.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(480.f, 445.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(210.f, 305.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(810.f, 335.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(420.f, 175.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(730.f, 175.f), sf::Vector2f(200.f, 50.f)));
}

void InGame::InitSprites()
{
	auto& sprite = sprites_["background"];
	sprite.setTexture(textureManager_.Get("background"));
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
}

void InGame::InitEntities()
{
	player_ = new Player(dt_, fixdt_, &textureManager_.Get("player"));
	player_->healthbar_ = new HealthBar(&textureManager_.Get("healthbar"));
}

void InGame::FixedUpdateEntities()
{
	player_->FixedUpdate();
	if(heart_)
	{
		heart_->FixedUpdate();
	}
}

void InGame::UpdateEntities()
{
	player_->ResolveCollision(platforms_);
	if(heart_)
	{
		player_->ResolveCollision(heart_);
	}
	player_->Update();
	if(!heart_)
	{
		SpawnHeart();
	}
	if(heart_ && !heart_->IsExist())
	{
		delete heart_;
		heart_ = nullptr;
	}
	else if(heart_)
	{
		heart_->Update();
		heart_->ResolveCollision(platforms_);
		heartSpawnClock_.restart();
	}
}