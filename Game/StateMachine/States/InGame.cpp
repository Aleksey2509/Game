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
}

void InGame::InitAssets()
{
	textureManager_.Load("player", "../Images/player.png");
	textureManager_.Load("background", "../Images/map.png");
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
}

void InGame::FixedUpdateEntities()
{
	player_->FixedUpdate();
}

void InGame::UpdateEntities()
{
	player_->ResolveCollision(platforms_);
	player_->Update();
}