#ifndef GAME_STATESMACHINE_STATES_ENDSCREEN_HPP
#define GAME_STATESMACHINE_STATES_ENDSCREEN_HPP

#include "StateMachine/States/AllStates.hpp"
#include "AssetsManager.hpp"
#include "CheckKey.hpp"
#include <utility>
#include <string>

class EndScreen : public State
{
public:

    EndScreen(StateMachine& machine);

	~EndScreen();

	virtual void Update();
	virtual void FixedUpdate();
    virtual void Render(sf::RenderTarget& target);


private:

    Button menuButton_;
    Button replayButton_;
    Button exitButton_;

    sf::Font font_;
    sf::Text GameOver_;

    AssetsManager<sf::Texture> textureManager_;
    std::unordered_map<std::string, sf::Sprite> sprites_;

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