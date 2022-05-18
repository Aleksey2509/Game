#ifndef GAME_UI_HEALTHBAR_HPP
#define GAME_UI_HEALTHBAR_HPP

#include <cstddef>
#include <SFML/Graphics.hpp>

class HealthBar : public sf::Drawable
{
public:
	HealthBar() = default;
	explicit HealthBar(sf::Texture* texture);
	~HealthBar();

	void Change(bool x);
	int GetHealthState() const;
private:
	sf::Sprite sprite_;
	sf::Texture* texture_;

	size_t curpos_ = 0;
	size_t coords_[3] = {0, 32, 64};

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif //GAME_UI_HEALTHBAR_HPP