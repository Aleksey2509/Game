#include "AllStates.hpp"

InPause::InPause(StateMachine& machine) : State(machine),
    continueButton_({200, 300}, {600, 100}, sf::Color::Transparent, "Return to game"),
    menuButton_({200, 600}, {600, 100}, sf::Color::Transparent, "Return to menu")
{
    textureManager_.Load("background", "../Images/map.png");
    auto& sprite = sprites_["background"];
	sprite.setTexture(textureManager_.Get("background"));
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));

    font_.loadFromFile("../Images/ComicSansMS.ttf");

    paused_.setFont(font_);
    paused_.setFillColor(sf::Color::Blue);
    paused_.setString("Paused");
    paused_.setPosition({380, 50});
    paused_.setCharacterSize(80);
}

InPause::~InPause() { }

void InPause::Update()
{
    continueButton_.Update(window_);

    if (continueButton_.ifPressed())
    {
        isRun = false;
        return;
    }

    menuButton_.Update(window_);
    if (menuButton_.ifPressed())
    {
        isRun = false;
        machine_.PopBackState();
        machine_.PushBackState(new InMenu(machine_));
        return;
    }
}


void InPause::FixedUpdate()
{

}

void InPause::Render(sf::RenderTarget& target)
{
    target.draw(sprites_["background"]);
    target.draw(paused_);
    continueButton_.Render(target);
    menuButton_.Render(target);
}
