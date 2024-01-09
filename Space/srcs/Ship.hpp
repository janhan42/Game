/**
 * @file Ship.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "Space.hpp"

class Ship
{
	public:
		Ship(sf::Vector2f pos);
		void	setPosition(sf::Vector2f pos);
		void	update();


	private:
		sf::RectangleShape	body;
		sf::Vector2f		position;
		sf::Vector2f		accelation;
		sf::Vector2f		velocity;
		float				mass;
};
