/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:06:56 by janhan            #+#    #+#             */
/*   Updated: 2024/05/07 17:02:10 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SFML/Graphics/View.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main(int ac, char **av)
{
	sf::RenderWindow window(sf::VideoMode(2000, 750), "cub3d");
	Player player(300, 300);
	window.setFramerateLimit(60);
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				player._press_buttons(event.key.code);
		}
		window.clear(sf::Color::Transparent);
		player.drawMap2D(window);
		player.drawRays3d(window);
		player.draw(window);
		window.display();
	}
}
