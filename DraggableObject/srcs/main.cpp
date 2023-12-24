/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:49:31 by janhan            #+#    #+#             */
/*   Updated: 2023/12/24 17:52:23 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <SFML/Graphics.hpp>
#include "DraggableObject.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "TEST");
	DraggableObject object;

	bool isDragging = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Resized)
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				object.setStartPoint(window);
			}
			else if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				object.setEndPoint(window);
				object.render();
			}
		}
		window.clear();
		object.draw(window);
		window.display();
	}
	return 0;
}
