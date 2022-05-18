#ifndef GAME_STATEMACHINE_STATES_ALLSTATES
#define GAME_STATEMACHINE_STATES_ALLSTATES

#include <random>
#include <list>

#include "AliveObjects/Entity.hpp"
#include "AliveObjects/Bullet.hpp"
#include "AliveObjects/Player.hpp"
#include "AssetsManager.hpp"
#include "CheckKey.hpp"
#include "Platform.hpp"
#include "UI/Button.hpp"
#include <utility>
#include <string>


class InMenu : public State
{
public:
    InMenu(StateMachine& machine);

	~InMenu();

	virtual void Update();
	virtual void FixedUpdate();
    virtual void Render(sf::RenderTarget& target);


private:
    AssetsManager<sf::Texture> textureManager_;
    std::unordered_map<std::string, sf::Sprite> sprites_;

    Button playButton_;
    // Button aboutButton_;
    Button exitButton_;
    void InitAssets();

    enum class ButtonPressed
    {
        NONE = 0,
        PLAY,
        EXIT
    };
    ButtonPressed pressed_ = ButtonPressed::NONE;
};


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

class InPause : public State
{
public:

    InPause(StateMachine& machine);

	~InPause();

	virtual void Update();
	virtual void FixedUpdate();
    virtual void Render(sf::RenderTarget& target);


private:
    AssetsManager<sf::Texture> textureManager_;
    std::unordered_map<std::string, sf::Sprite> sprites_;

    Button continueButton_;
    Button menuButton_;

    sf::Font font_;
    sf::Text paused_;
    void InitAssets();

    enum class ButtonPressed
    {
        NONE = 0,
        MENU,
        PLAY
    };
    ButtonPressed pressed_ = ButtonPressed::NONE;
};


class EndScreen : public State
{
public:

    EndScreen(StateMachine& machine);

	~EndScreen();

	virtual void Update();
	virtual void FixedUpdate();
    virtual void Render(sf::RenderTarget& target);


private:
    AssetsManager<sf::Texture> textureManager_;
    std::unordered_map<std::string, sf::Sprite> sprites_;

    Button menuButton_;
    Button replayButton_;
    Button exitButton_;

    sf::Font font_;
    sf::Text GameOver_;
    void InitAssets();

    enum class ButtonPressed
    {
        NONE = 0,
        MENU,
        PLAY,
        EXIT
    };
    ButtonPressed pressed_ = ButtonPressed::NONE;
};



#endif