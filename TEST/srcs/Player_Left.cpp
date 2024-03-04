/**
 * @file Player1.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Player_Left.hpp"
#include "PlayerStick.hpp"
#include "SFML/Window/Keyboard.hpp"

Player_Left::Player_Left(float x, float y, float width, float height, float speed)
: PlayerStick(x, y, width, height, speed) {}

void	Player_Left::update(sf::Event& event, float deltaTime)
{
	if (event.key.code == sf::Keyboard::W)
	{
		moveUp(deltaTime);
	}
	if (event.key.code == sf::Keyboard::S)
	{
		moveDown(deltaTime);
	}
}
