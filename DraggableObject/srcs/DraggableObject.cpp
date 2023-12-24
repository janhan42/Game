/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DraggableObject.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:52:52 by janhan            #+#    #+#             */
/*   Updated: 2023/12/24 12:04:31 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DraggableObject.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include <cmath>

DraggableObject::DraggableObject()
{

}

void	DraggableObject::draw(sf::RenderWindow& window)
{
	window.draw(object);
}

void	DraggableObject::setStartPoint(sf::RenderWindow& window)
{
	startPoint = sf::Mouse::getPosition(window);
}

void	DraggableObject::setEndPoint(sf::RenderWindow& window)
{
	endPoint = sf::Mouse::getPosition(window);
}

sf::Vector2i	DraggableObject::getStartPoint()
{
	return this->startPoint;
}

sf::Vector2i	DraggableObject::getEndPoint()
{
	return this->endPoint;
}

void	DraggableObject::render()
{
	object.setSize(sf::Vector2f(endPoint.x - startPoint.x, endPoint.y - startPoint.y));
	object.setFillColor(sf::Color::White);
	object.setPosition(startPoint.x, startPoint.y);
}

bool	DraggableObject::isMouseOver(const sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	return (object.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))));
}
