#include "CheckKey.hpp"

CheckKey::CheckKey()
{
	for(char i = 'A'; i <= 'Z'; i++)
	{
		keys_.insert({i, false});
	}
	buttons_.insert({'L', false});
	buttons_.insert({'R', false});
	buttons_.insert({'M', false});
}

const bool CheckKey::CheckKeyboardKey(char key)
{
	return keys_[key];
}

const bool CheckKey::CheckMouseButton(char button)
{
	return buttons_[button];
}

void CheckKey::Update()
{
	for(char i = 'A'; i <= 'Z'; i++)
	{
		keys_[i] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i - 'A'));
	}
	buttons_['L'] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	buttons_['R'] = sf::Mouse::isButtonPressed(sf::Mouse::Right);
	buttons_['M'] = sf::Mouse::isButtonPressed(sf::Mouse::Middle);
}