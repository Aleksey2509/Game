#ifndef ENGINE_COLLISIONBOX_HPP
#define ENGINE_COLLISIONBOX_HPP

#include <SFML/System/Vector2.hpp>

struct CollisionBox
{
public:
	CollisionBox();
	CollisionBox(const sf::Vector2f& sz, const sf::Vector2f& pos);

	bool CheckCollision(const CollisionBox& other, sf::Vector2f& result) const;
	sf::Vector2f sz_;
	sf::Vector2f pos_;
};

inline bool operator==(const CollisionBox lhs, const CollisionBox rhs)
{
    return ((lhs.sz_ == rhs.sz_) && (lhs.pos_ == rhs.pos_));
}

#endif //ENGINE_COLLISIONBOX_HPP