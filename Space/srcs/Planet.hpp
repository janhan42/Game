/**
 * @file Planet.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "Space.hpp"

class Planet
{
	public:
		Planet(sf::Vector2f center, float radius, float gravityStrength);
		sf::Vector2f GetGravityForce(const sf::Vector2f& objectPosition) const;
		void Draw(sf::RenderWindow& window) const;

	private:
		sf::Vector2f center;
		float radius;
		float gravityStrength;
		sf::CircleShape shape;
};
