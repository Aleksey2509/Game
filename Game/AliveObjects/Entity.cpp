#include "Entity.hpp"

Entity::Entity(float dt, float fixdt) : dt_(dt), fixdt(fixdt_) {}

void Entity::draw(sf::RenderTarget& target) const
{
	target.draw(*i_drawable);
}