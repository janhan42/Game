/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:24:55 by janhan            #+#    #+#             */
/*   Updated: 2023/12/19 23:24:55 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "core.hpp"

int	main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Space");
	window.setFramerateLimit(60);
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			
		}
	}
}