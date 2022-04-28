#ifndef ENGINE_COLLISIONBOX_HPP
#define ENGINE_COLLISIONBOX_HPP

#include <SFML/System/Vector2.hpp>

struct CollisionBox
{
public:
	CollisionBox(const sf::Vector2f& sz, const sf::Vector2f& pos): sz_(sz), pos_(pos) {}

	sf::Vector2f sz_;
	sf::Vector2f pos_;
};

#endif //ENGINE_COLLISIONBOX_HPP