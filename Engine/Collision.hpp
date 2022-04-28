#ifndef ENGINE_COLLISION_HPP
#define ENGINE_COLLISION_HPP

struct Collision
{
public:
	Collision(CollisionBox& body);

	bool CheckCollision(CollisionBox& other, sf::Vector2f result) const;
	CollisionBox& body_;
};

#endif //ENGINE_COLLISION_HPP