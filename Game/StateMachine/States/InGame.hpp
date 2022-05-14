#ifndef GAME_STATEMACHINE_STATES_INGAME_HPP
#define GAME_STATEMACHINE_STATES_INGAME_HPP

#include "AliveObjects/Entity.hpp"
#include "AssetsManager.hpp"
#include "Platform.hpp"
#include "StateMachine/StateMachine.hpp"
#include "AliveObjects/Player.hpp"

class InGame : public State
{
public:
	InGame(StateMachine& machine);
	~InGame();

	virtual void FixedUpdate();
	virtual void Update();
	virtual void Render(sf::RenderTarget& target);
private:
	Player* player_;

	sf::Clock clock_;
	sf::Clock timeClock_;
	std::unordered_map<std::string, sf::Sprite> sprites_;
	std::vector<Platform> platforms_;
	AssetsManager<sf::Texture> textureManager_;

	void InitEntities();
	void UpdateEntities();
	void FixedUpdateEntities();
	void InitAssets();
	void InitSprites();
	void InitPlatforms();
};

#endif //GAME_STATEMACHINE_STATES_INGAME_HPP