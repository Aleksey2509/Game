#include "HealthBar.hpp"

HealthBar::HealthBar()
{
	texture_.loadFromFile("../../Images/healthbar.png");
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(0, coords_[curpos_], 96, 32));
	sprite_.setScale(sf::Vector2f(2.f, 2.f));
	sprite_.setPosition(sf::Vector2f(65.f, 35.f));
}

HealthBar::~HealthBar() {}

void HealthBar::Change(bool x)
{
	if(x && curpos_ < 3)
	{
		curpos_++;
	}
	else if(!x && curpos_ > 0)
	{
		curpos_--;
	}
	sprite_.setTextureRect(sf::IntRect(0, coords_[curpos_], 96, 32));
}

int HealthBar::GetHealthState() const
{
	return 3 - curpos_;
}

void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_);
}