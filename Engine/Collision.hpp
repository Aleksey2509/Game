#ifndef ENGINE_COLLISION_HPP
#define ENGINE_COLLISION_HPP

#include "CollisionBox.hpp"
struct Collision
{
public:
	Collision(CollisionBox& body);

	bool CheckCollision(Collision& other, sf::Vector2f& result) const;
	CollisionBox& body_;
};

#endif //ENGINE_COLLISION_HPP