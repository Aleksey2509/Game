#include "Platform.hpp"

Platform::Platform(sf::Vector2f sz, sf::Vector2f pos): box_(size, pos) {}

const CollisionBox& Platform::getBox() const
{
	return box_;
}