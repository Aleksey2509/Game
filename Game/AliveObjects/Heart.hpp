#ifndef GAME_ALIVEOBJECTS_HEART_HPP
#define GAME_ALIVEOBJECTS_HEART_HPP

#include "FixedClock.hpp"
#include "Animation.hpp"
#include "AliveObjects/Entity.hpp"
#include "Platform.hpp"
#include <cstddef>
#include <vector>

class Heart : public Entity
{
public:
	Heart(const float& dt, const float& fixdt, sf::Texture* texture);
	virtual ~Heart();

	virtual void FixedUpdate();
	virtual void Update();

	void ResolveCollision(std::vector<Platform>& platforms);
	bool IsExist() const;
	bool exist_ = true;
private:
	bool grounded_ = false;
	Animation animations_;

	FixedClock deSpawnClock_;
	FixedClock realDeSpawnClock_;
	FixedClock disapClock_;

	const float deSpawnTime_ = 3.f;
	float disapTime_ = 0.5f;

	bool disap_ = false;
	size_t curclr_ = 0;
	const sf::Color colors_[4] =
	{
		sf::Color(255, 255, 255, 80),
		sf::Color(255, 255, 255, 255),
		sf::Color(255, 255, 255, 80),
		sf::Color(255, 255, 255, 255),
	};

	void Animate();
	void InitBody();
	void InitAnimations();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //GAME_ALIVEOBJECTS_HEART_HPP