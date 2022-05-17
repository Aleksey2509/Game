#ifndef GAME_ALIVEOBJECTS_PLAYER_HPP
#define GAME_ALIVEOBJECTS_PLAYER_HPP

#include "Animation.hpp"
#include "AliveObjects/Entity.hpp"
#include "Platform.hpp"
#include "Heart.hpp"
#include "UI/HealthBar.hpp"
#include "Bullet.hpp"
#include <unordered_map>
#include <string>
#include <list>

class Player final : public Entity
{
public:
	Player(const float& dt, const float& fixdt, sf::Texture* texture);
	virtual ~Player();

	virtual void FixedUpdate();
	virtual void Update();

	void ResolveCollision(std::vector<Platform>& platforms);
	void ResolveCollision(Heart* heart);
	void ResolveCollision(std::list<Bullet>& bullets);

	bool IsAlive() const;
	HealthBar* healthbar_;
private:
	sf::Vector2f velocity_;
	bool alive_ = true;
	float moveSpeed_ = 420.f;
	float gravity_ = 4000.f;
	float jumpVelocity_ = -1200.f;
	float accel_ = 0.8f;

	bool grounded_ = true;
	bool grabbing_ = false;
	bool wasGrounded_ = false;

	bool moveable_ = true;

	bool hit_ = false;
	int currhit_ = 0;
	sf::Clock hitTimer_;

	const sf::Vector2i playerSize_ = sf::Vector2i(96, 84);
	std::unordered_map<std::string, Animation> animations_;

	void Animate();
	void KeepInBorders();
	void Move();
	void UpdateTimer();
	void UpdateVelocity();
	void InitAnimations();
	void InitBody();
	void InitBox();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif //GAME_ALIVEOBJECTS_PLAYER_HPP