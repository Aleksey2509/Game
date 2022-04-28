#ifndef ENGINE_CHECKKEY_HPP
#define ENGINE_CHECKKEY_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <unordered_map>

class CheckKey
{
public:
	CheckKey();

	//Update status of all buttons
	void Update();

	//if key is pressed return true, otherwise return false
	const bool CheckKeyboardKey(char key);
	//if button is pressed return true, otherwise return false
	const bool CheckMouseButton(char button);
private:
	std::unordered_map<char, bool> keys_;
	std::unordered_map<char, bool> buttons_;
};


#endif //ENGINE_CHECKKEY_HPP