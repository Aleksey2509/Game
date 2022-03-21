#ifndef SFML_INCLUDE_VISUAL_HPP
#define SFML_INCLUDE_VISUAL_HPP

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <utility>

#include "../include/Platform.hpp"

const auto BACKGROUND = sf::Color(0, 32, 255);

class Visual : public sf::Sprite
{
	private:
	// Texture function to draw platforms
	sf::RenderTexture texture_;
	// Vector of rectangles (width, height, coordinates)
	std::vector<sf::RectangleShape> rects_;
	// Color[i] is color of the rectangle[i]
	std::vector<sf::Color> colors_;

	// Width of the drawing screen
	uint32_t width_;
	// Height of the drawing screen
	uint32_t height_;

	// Platform class
	Platform& platforms_;

	// Width of the rectangle
	float rects_width_;
	// Height of the rectangle
	float rects_height_;

	public:
	// Constructor of the Visual
	// max_width - width of the screen
	// max_height - height of the screen
	// platforms - platforms which will be drawn
	Visual(uint32_t max_width, uint32_t max_height, Platform& platforms);
	// Render function to draw platforms which contain in Visual class
	void render();
};

#endif  // SFML_INCLUDE_VISUAL_HPP