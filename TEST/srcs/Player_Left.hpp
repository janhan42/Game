/**
 * @file Player1.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "PlayerStick.hpp"
#pragma once

class Player_Left : public PlayerStick
{
	public:
		Player_Left(float x, float y, float width, float height, float speed);
		void	update(sf::Event& event, float deltaTime) override;
};
