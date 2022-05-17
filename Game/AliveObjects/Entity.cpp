#include "Entity.hpp"

Entity::Entity(const float& dt, const float& fixdt) : dt_(dt), fixdt_(fixdt) {}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*drawable_);
}

const CollisionBox& Entity::GetBox() const
{
	return box_;
}