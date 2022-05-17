#ifndef GAME_STATEMACHINE_STATES_BUTTON_HPP
#define GAME_STATEMACHINE_STATES_BUTTON_HPP

#include "StateMachine/StateMachine.hpp"
#include "AssetsManager.hpp"
#include "CheckKey.hpp"
#include <utility>
#include <string>
#include <iostream>

class Button
{

public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size, sf::Color color, const std::string& text) :
        color_(color)
    {
        textFont_.loadFromFile("../Images/ComicSansMS.ttf");

        text_.setFont(textFont_);
        text_.setFillColor(sf::Color::Yellow);
        text_.setString(text);
        text_.setPosition(position);
        text_.setCharacterSize(80);

        sf::RectangleShape shape(size);
        shape.setPosition(position);
        shape.setFillColor(color_);

        shape_ = shape;
    }

	void FixedUpdate() {};
    void Update(sf::Window& window)
    {
        if (CheckKey::CheckMouseButton('L'))
        {
            int stillPressed = true;
            while (ifContainsPoint(sf::Mouse::getPosition(window)) && stillPressed)
            {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        stillPressed = false;
                        if (ifContainsPoint(sf::Mouse::getPosition(window)))
                        {
                            pressed_ = true;
                        }
                    }
            }
        }
    }

    void Render(sf::RenderTarget& target)
    {
        sf::RectangleShape shapeToDraw = shape_;
        if (pressed_)
            shapeToDraw.setFillColor(sf::Color::Red);

        target.draw(shape_);
        target.draw(text_);
    }

    bool ifPressed() const { return pressed_; };

private:
    bool ifContainsPoint (const sf::Vector2i& point)
    {
        sf::Vector2f leftTop = shape_.getPosition();

        float leftBorder  = leftTop.x;
        float rightBorder = leftTop.x + shape_.getSize().x;
        float lowerBorder = leftTop.y;
        float upperBorder = leftTop.y + shape_.getSize().y;

        if ((point.x > leftBorder) && (point.x < rightBorder) && (point.y > lowerBorder) && (point.y < upperBorder))
            return true;

        return false;
    }

    sf::Color color_;
    sf::Font textFont_;
    sf::Text text_;
    sf::RectangleShape shape_;
    bool pressed_ = false;
};


#endif