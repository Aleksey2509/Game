#include "../include/Platform.hpp"

#include <ctime>
#include <random>

Platform::Platform(uint8_t amount, uint32_t max_width, uint32_t max_height)
    : amount_(amount)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib_h(1, max_height);
	std::uniform_int_distribution<> distrib_w(1, max_width);

	coords temp;
	for (uint8_t i = 0; i < amount_; i++)
	{
		temp.first = distrib_w(gen);
		temp.second = distrib_h(gen);
		blocks_.push_back(temp);
	}
}

uint8_t Platform::getamount() { return amount_; }

coords Platform::getblock(uint8_t pos)
{
	if (pos > amount_)
	{
		return coords(0, 0);
	}
	return blocks_[pos];
}