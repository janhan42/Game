/**
 * @file food.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>

class Food
{
	public:

		Food(float quantity, sf::Vector2f position, size_t id);
		void		consume(float amount);
		float		getQuantity() const;
		sf::Vector2f	getPosition() const;
		bool		isConsumed() const;
		size_t		getId() const;
		void		draw(sf::RenderWindow& window);
	private:
		sf::CircleShape FoodShape;
		float			_quantity;
		sf::Vector2f	_position;
		size_t			_id;
};
