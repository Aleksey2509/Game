#include "Entity.hpp"

Entity::Entity(float dt, float fixdt) : dt_(dt), fixdt_(fixdt) {}

void Entity::draw(sf::RenderTarget& target) const
{
	target.draw(*drawable_);
}