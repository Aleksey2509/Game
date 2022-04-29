#ifndef GAME_STATEMACHINE_STATES_INGAME_HPP
#define GAME_STATEMACHINE_STATES_INGAME_HPP

//#include "../../AliveObjects/Entity.hpp"
#include "AssetsManager.hpp"
#include "Platform.hpp"
#include "StateMachine/StateMachine.hpp"

class InGame : public State
{
public:
	InGame(StateMachine& machine);
	~InGame();

	virtual void FixedUpdate();
	virtual void Update();
	virtual void Render(sf::RenderTarget& target);
private:
	sf::Clock clock_;
	std::unordered_map<std::string, sf::Sprite> sprites_;
	std::vector<Platform> platforms_;
	AssetsManager<sf::Texture> textureManager_;
	sf::Clock timeClock_;
/*
	void InitEntities();
	void UpdateEntities();
	void FixedUpdateEntities();
*/
	void InitAssets();
	void InitSprites();
	void InitPlatforms();
};

#endif //GAME_STATEMACHINE_STATES_INGAME_HPP