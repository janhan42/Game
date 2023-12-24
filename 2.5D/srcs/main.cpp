/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:12:47 by janhan            #+#    #+#             */
/*   Updated: 2023/12/24 18:40:54 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ball.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

void    onUserCreate(std::vector<Ball> vecBall, sf::RenderWindow& window)
{
	// Define Circle Model
	vecBall.push_back({ 0.0f, 0.0f });
	float fDefaultRad = 8.0f;

}

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "TEST");
	window.setFramerateLimit(60);

	std::vector<Ball> vecBall;
	for (int i = 0; i <10; i++)
		vecBall.push_back(Ball(rand() % window.getSize().x, rand() % window.getSize().y));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

			}
		}
		window.clear();
		for (int i = 0; i < vecBall.size(); i++)
			vecBall[i].updatePhysics(vecBall, window);
		for (int i = 0; i < vecBall.size(); i++)
			vecBall[i].draw(window);
		window.display();
	}
}
