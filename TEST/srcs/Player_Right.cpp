/**
 * @file Player_Right.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Player_Right.hpp"
#include "SFML/Window/Keyboard.hpp"

Player_Right::Player_Right(float x, float y, float width, float height, float speed)
:	PlayerStick(x, y, width, height, speed) {}

void	Player_Right::update(sf::Event& event, float deltaTime)
{
	if (event.key.code == sf::Keyboard::Up)
	{
		moveUp(deltaTime);
	}
	if (event.key.code == sf::Keyboard::Down)
	{
		moveDown(deltaTime);
	}
}
