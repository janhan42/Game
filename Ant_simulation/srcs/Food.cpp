/**
 * @file food.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Food.hpp"
#include "SFML/System/Vector2.hpp"
#include <sys/_types/_size_t.h>
#include <sys/signal.h>

Food::Food(float quantity, sf::Vector2f position, size_t id):
_quantity(quantity)
,_position(position)
{
	this->_id = id;
	FoodShape.setPosition(position.x, position.y);
	FoodShape.setRadius(quantity / 2);
	FoodShape.setFillColor(sf::Color::Green);
}

void	Food::consume(float amount)
{
	_quantity -= amount;
	if (_quantity < 0) _quantity = 0;
}

float	Food::getQuantity() const
{
	return _quantity;
}

sf::Vector2f Food::getPosition() const
{
	return _position;
}

/**
 * @brief
 * 음식을 다 먹었다면
 * @return true
 * 음식이 남아있다면
 * @return false
 */
bool	Food::isConsumed() const
{
	return _quantity <= 0;
}

void	Food::draw(sf::RenderWindow& window)
{
	window.draw(FoodShape);
}

size_t	Food::getId() const
{
	return this->_id;
}
