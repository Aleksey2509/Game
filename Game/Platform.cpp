#include "Platform.hpp"

Platform::Platform(sf::Vector2f sz, sf::Vector2f pos): box_(sz, pos) {}

const CollisionBox& Platform::GetBox() const
{
	return box_;
}