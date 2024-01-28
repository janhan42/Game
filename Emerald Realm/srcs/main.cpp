/**
 * @file main.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <SFML/Graphics.hpp>
#include <sys/errno.h>
#include "Player.hpp"

int	main(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Emerald Realm");
	window.setFramerateLimit(60);
	sf::Event event;
	Player player(10);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				player.inPressed(event.key.code, player.PRESSED);
			}
			if (event.type == sf::Event::KeyReleased)
			{
				player.inReleased(event.key.code, player.RELEASED);
			}
		}
		player.upDate();
		window.clear(sf::Color());
		window.draw(player.getSprite());
		window.display();
	}
}