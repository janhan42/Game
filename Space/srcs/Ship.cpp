/**
 * @file Ship.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Space.hpp"
#include "SFML/Graphics/Color.hpp"

Ship::Ship(sf::Vector2f pos)
: position(pos)
, accelation(0.0f, 0.0f)
, velocity(0.0f, 0.0f)
, mass(280000)
{
	body.setSize(sf::Vector2f(50, 100));
	body.setPosition(position);
	body.setFillColor(sf::Color::White);
}
