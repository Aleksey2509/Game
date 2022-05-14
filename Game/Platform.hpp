#ifndef GAME_PLATFORM_HPP
#define GAME_PLATFORM_HPP

#include <SFML/Graphics.hpp>
#include "CollisionBox.hpp"

class Platform : public sf::Sprite
{
public:
	Platform(sf::Vector2f position, sf::Vector2f size);

	const CollisionBox& GetBox() const;
private:
	CollisionBox box_;
};

#endif  // GAME_PLATFORM_HPP