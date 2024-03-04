/**
 * @file Ball.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "SFML/Graphics/CircleShape.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player_Left.hpp"
#include "Player_Right.hpp"
#pragma once

class Ball
{
	public:
		sf::CircleShape		shape;
		sf::Vector2f		velocity;
		sf::Clock clock; // 시간 측정용
		sf::SoundBuffer		WallSound;
		sf::SoundBuffer		StickSound;
		sf::SoundBuffer		ScoreSound;
		sf::Sound			sound;
		bool isResetting = false;
		Ball(float mX, float mY);

		void	draw(sf::RenderWindow& window);
		void	update(const PlayerStick& playerLeft, const PlayerStick& playerRight, sf::RenderWindow& window, int& scoreLeft, int& scoreRight);
		void	resetBall(sf::RenderWindow& window);
		sf::Vector2f	getPosition();
	private:
		float left();
		float right();
		float top();
		float bottom();
};
