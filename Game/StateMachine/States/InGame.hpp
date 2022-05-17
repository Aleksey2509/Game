#ifndef GAME_STATEMACHINE_STATES_INGAME_HPP
#define GAME_STATEMACHINE_STATES_INGAME_HPP

#include <random>
#include <list>

#include "AliveObjects/Entity.hpp"
#include "AliveObjects/Bullet.hpp"
#include "AliveObjects/Player.hpp"
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
	Player* player_;
	Heart* heart_ = nullptr;

	sf::Clock clock_;
	sf::Clock timeClock_;
	sf::Clock heartSpawnClock_;

	std::unordered_map<std::string, sf::Sprite> sprites_;
	std::vector<Platform> platforms_;
    std::list<Bullet> bullets_;
	AssetsManager<sf::Texture> textureManager_;

	const size_t maxBullets = 5;

	void SpawnHeart();
	void InitEntities();
	void UpdateEntities();
	void FixedUpdateEntities();
	void InitAssets();
	void InitSprites();
	void InitPlatforms();
    void InitBullet();
    void resolveBulletCollisions();
    void removeDeadBullets();
};

#endif //GAME_STATEMACHINE_STATES_INGAME_HPP