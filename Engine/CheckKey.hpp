#ifndef ENGINE_CHECKKEY_HPP
#define ENGINE_CHECKKEY_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <unordered_map>

class CheckKey
{
public:
	//Update status of all buttons
	static void Update();
	static void Init();
	//if key is pressed return true, otherwise return false
	const static bool CheckKeyboardKey(char key);
	//if button is pressed return true, otherwise return false
	const static bool CheckMouseButton(char button);
private:
	CheckKey() {}
	~CheckKey() {}
	static std::unordered_map<char, bool> keys_;
	static std::unordered_map<char, bool> buttons_;
};


#endif //ENGINE_CHECKKEY_HPP