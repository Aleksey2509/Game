#ifndef GAME_STATEMACHINE_STATES_INMENU_HPP
#define GAME_STATEMACHINE_STATES_INMENU_HPP


#include "StateMachine/States/InGame.hpp"
#include "AssetsManager.hpp"
#include "Button.hpp"
#include "CheckKey.hpp"
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

#endif