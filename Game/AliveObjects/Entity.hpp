#ifndef GAME_ALIVEOBJECTS_HPP
#define GAME_ALIVEOBJECTS_HPP

class Entity : public sf::Drawable
{
public:
	Entity(float dt, float fixdt);
	virtual ~Entity();

	virtual void FixedUpdate() = 0;
	virtual void Update() = 0;
private:
	CollisionBox box_;

	sf::Texture* texture_ = nullptr;
	sf::Texture* drawable_ = nullptr;

	float dt_;
	float fixdt_;

	virtual void draw(sf::RenderTarget& target) const;
}


#endif //GAME_ALIVEOBJECTS_HPP