#include "AllStates.hpp"

EndScreen::EndScreen(StateMachine& machine) : State(machine),
    menuButton_({190, 300}, {620, 100}, sf::Color::Transparent, "Go back to menu"),
    replayButton_({315, 500}, {370, 100}, sf::Color::Transparent, "Play again"),
    exitButton_({410, 700}, {180, 100}, sf::Color::Transparent, "Quit")
{
    textureManager_.Load("background", "../Images/map.png");
    auto& sprite = sprites_["background"];
	sprite.setTexture(textureManager_.Get("background"));
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));

    font_.loadFromFile("../Images/ComicSansMS.ttf");

    GameOver_.setFont(font_);
    GameOver_.setFillColor(sf::Color::Red);
    GameOver_.setString("GAME OVER");
    GameOver_.setPosition({250, 50});
    GameOver_.setCharacterSize(80);
}

EndScreen::~EndScreen() { }

void EndScreen::Update()
{
    replayButton_.Update(window_);
    if (replayButton_.ifPressed())
    {
        machine_.PushBackState(new InGame(machine_));
        isRun = false;
        return;
    }

    menuButton_.Update(window_);
    if (menuButton_.ifPressed())
    {
        machine_.PushBackState(new InMenu(machine_));
        isRun = false;
        return;
    }

    exitButton_.Update(window_);
    if (exitButton_.ifPressed())
    {
        isRun = false;
        return;
    }
}


void EndScreen::FixedUpdate()
{

}

void EndScreen::Render(sf::RenderTarget& target)
{
    target.draw(sprites_["background"]);
    target.draw(GameOver_);
    replayButton_.Render(target);
    menuButton_.Render(target);
    exitButton_.Render(target);
}