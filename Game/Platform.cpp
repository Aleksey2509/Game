#include "Platform.hpp"

Platform::Platform(sf::Vector2f pos, sf::Vector2f sz): box_(sz, pos) {}

const CollisionBox& Platform::GetBox() const
{
	return box_;
}