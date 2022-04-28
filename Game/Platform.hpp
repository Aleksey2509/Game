#ifndef SFML_INCLUDE_PLATFORM_HPP
#define SFML_INCLUDE_PLATFORM_HPP

#include <SFML/Graphics.hpp>
#include <CollisionBox.hpp>

class Platform : public sf::Sprite
{
public:
	Platform(sf::Vector2f position, sf::Vector2f size);
private:
	CollisionBox box_;
};

#endif  // SFML_INCLUDE_PLATFORM_HPP