#include "../include/Visual.hpp"

Visual::Visual(uint32_t max_width, uint32_t max_height, Platform& platforms)
    : width_(max_width), height_(max_height), platforms_(platforms)
{
	rects_height_ = static_cast<float>(height_) / 100;
	rects_width_ = static_cast<float>(width_) / 10;

	rects_ = std::vector<sf::RectangleShape>(platforms_.getamount());
	colors_ = std::vector<sf::Color>(platforms_.getamount(), sf::Color::Green);

	texture_.create(width_, height_);
	setTexture(texture_.getTexture());
}

void Visual::render()
{
	texture_.clear(BACKGROUND);
	coords temp;
	for (uint8_t i = 0, j = rects_.size(); i < j; i++)
	{
		rects_[i].setSize(sf::Vector2f(rects_width_, rects_height_));
		temp = platforms_.getblock(i);
		rects_[i].setPosition(temp.first, temp.second);
		rects_[i].setFillColor(colors_[i]);
		texture_.draw(rects_[i]);
	}
	texture_.display();
}