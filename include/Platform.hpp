#ifndef SFML_INCLUDE_PLATFORM_HPP
#define SFML_INCLUDE_PLATFORM_HPP

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <utility>
#include <vector>

using coords = std::pair<uint32_t, uint32_t>;

class Platform : public sf::Sprite
{
public:
	//Platform constructor
	//Generate amount of platforms with maximum width (max_width) and maximum height (max_height)
	//Generating is made with uniform_int_distribution, mt19937, random_device
	Platform(uint8_t amount, uint32_t max_width, uint32_t max_height);
	//Get block on position [pos]
	coords getblock(uint8_t pos);
	//Get amount of blocks
	uint8_t getamount();

private:
	//Amount of platforms
	uint8_t amount_;
	//Vector of blocks contains coords points
	std::vector<coords> blocks_;
};

#endif //SFML_INCLUDE_PLATFORM_HPP