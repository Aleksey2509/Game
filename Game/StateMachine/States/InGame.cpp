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
	textureManager_.Load("background", "../../../map.png");
}

void InGame::InitPlatforms() {}

void InGame::InitSprites() {}