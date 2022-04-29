#include "InGame.hpp"

InGame::InGame(StateMachine& machine) : State(machine)
{
	InitPlatforms();
	InitAssets();
	InitSprites();
}

InGame::~InGame() {}

void InGame::FixedUpdate() {}

void InGame::Update() {}

void InGame::Render(sf::RenderTarget& target)
{
	target.draw(sprites_["background"]);
}

void InGame::InitAssets()
{
	textureManager_.Load("background", "../Images/map.png");
}

void InGame::InitPlatforms() {}

void InGame::InitSprites()
{
	auto& sprite = sprites_["background"];
	sprite.setTexture(textureManager_.Get("background"));
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
}