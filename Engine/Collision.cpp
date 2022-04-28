#include "Collision.hpp"

Collision::Collision(CollisionBox& body): body_(body) {}

bool Collision::CheckCollision(Collision& other, sf::Vector2f& result) const
{
	const sf::Vector2f dif = other.body_.pos_ - body_.pos_;
	sf::Vector2f absdif{dif};
	absdif.x = (absdif.x < 0.f ? -absdif.x : absdif.x);
	absdif.y = (absdif.y < 0.f ? -absdif.y : absdif.y);

	const sf::Vector2f possibledif = (other.body_.sz_ + body_.sz_) / 2.f;
	const sf::Vector2f intersect = absdif - possibledif;

	if(intersect.x < 0.f && intersect.y < 0.f)
	{
		if(intersect.x > intersect.y)
		{
			result.x = (dif.x > 0.f ? intersect.x : -intersect.x);
		}
		else
		{
			result.y = (dif.y > 0.f ? intersect.y : -intersect.y);
		}
		return true;
	}
	return false;
}