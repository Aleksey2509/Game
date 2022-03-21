#include <SFML/Graphics.hpp>

#include "../include/Platform.hpp"
#include "../include/Visual.hpp"

int main()
{
	sf::VideoMode def = sf::VideoMode::getDesktopMode();
	const uint32_t HEIGHT = def.height;
	const uint32_t WIDTH = def.width;
	const uint8_t kDataNum = 10;

	sf::RenderWindow window(def, "Bulletoid");

	sf::Event event;

	Platform platforms(kDataNum, WIDTH, HEIGHT);
	Visual vis(WIDTH, HEIGHT, platforms);

	vis.setPosition(0, 0);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						window.close();
						break;
					default:
						break;
				}
			}
		}
		vis.render();
		window.clear(BACKGROUND);
		window.draw(vis);
		window.display();
	}

	return 0;
}