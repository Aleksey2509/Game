#include "InMenu.hpp"

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
        machine_.PushState(new InGame(machine_));
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


// void InMenu::FixedUpdate()
// {
//     playButton_.setColor(Color::White);
//     aboutButton_.setColor(Color::White);
//     exitButton_.setColor(Color::White);
//     hoveringOverButton = 0;
//     window.clear(Color(129, 181, 221));

//     if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window)))
//     {
//         menu1.setColor(Color::Blue);
//         hoveringOverButton = 1;
//     }
//     if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window)))
//     {
//         menu2.setColor(Color::Blue);
//         hoveringOverButton = 2;
//     }
//     if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window)))
//     {
//         menu3.setColor(Color::Blue);
//         hoveringOverButton = 3;
//     }

//     if (Mouse::isButtonPressed(Mouse::Left))
//     {
//         if (hoveringOverButton == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
//         if (hoveringOverButton == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
//         if (hoveringOverButton == 3)  { window.close(); isMenu = false; }

//     }

//     window.draw(playButton_);
//     window.draw(aboutButton_);
//     window.draw(exitButton_);
    
//     window.display();
// }