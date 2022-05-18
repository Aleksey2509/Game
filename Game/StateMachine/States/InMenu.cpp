#include "AllStates.hpp"

InMenu::InMenu(StateMachine& machine) : State(machine),
    playButton_({275, 200}, {450, 100}, sf::Color::Transparent, "Start Game"),
    exitButton_({410, 600}, {180, 100}, sf::Color::Transparent, "Quit")
{
    textureManager_.Load("background", "../Images/map.png");
    auto& sprite = sprites_["background"];
	sprite.setTexture(textureManager_.Get("background"));
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
}

InMenu::~InMenu() { }

void InMenu::Update()
{
    playButton_.Update(window_);

    if (playButton_.ifPressed())
    {
        machine_.PushBackState(new InGame(machine_));
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


void InMenu::FixedUpdate()
{

}

void InMenu::Render(sf::RenderTarget& target)
{
    target.draw(sprites_["background"]);
    playButton_.Render(target);
    exitButton_.Render(target);
}
