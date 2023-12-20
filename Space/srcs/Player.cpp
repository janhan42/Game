/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:35:44 by janhan            #+#    #+#             */
/*   Updated: 2023/12/19 23:38:23 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Joystick.hpp"
#include "SFML/Window/Keyboard.hpp"

Player::Player(float x, float y) :
isUp(false),
isDown(false),
isLeft(false),
isRight(false),
velcityY(0.0f),
gravity(9.8f)
{
	rect.setSize(sf::Vector2f(x, y));
}

void	Player::processEvents(sf::Keyboard::Key key, bool checkPressed)
{
	if (checkPressed)
	{
		if (key == sf::Keyboard::W && !isJumping)
		{
			jump();
		}
		if (key == sf::Keyboard::S)
			isDown = true;
		if (key == sf::Keyboard::A)
			isLeft = true;
		if (key == sf::Keyboard::D)
			isRight = true;
	}
	else
	{
		isUp = isDown = isLeft = isRight = false;
	}
}

void	Player::jump()
{
	isJumping = true;
	velcityY = -60.f;
}

void	Player::update(float deltaTime)
{
	applyGravity(deltaTime);
	sf::Vector2f movement = sf::Vector2f(0.0f, velcityY) * deltaTime;
	if (isUp)
		movement.y -= 5.0;
	if (isDown)
		movement.y += 5.0;
	if (isLeft)
		movement.x -= 5.0;
	if (isRight)
		movement.x += 5.0;

	rect.move(movement);
	limitToScreenBounds();
	if (rect.getPosition().y + rect.getSize().y >= 600)
	{
		isJumping = false;
		rect.setPosition(rect.getPosition().x, 800 - rect.getSize().y);
	}
}


