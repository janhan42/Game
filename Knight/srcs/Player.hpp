/**
 * @file Player.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "Player.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <vector>

enum	State
		{
			Idle
			,Jump
			,Left
			,Right
			,Attack
			,Crouch
			,CrouchAttack
			,CrouchWalkRight
			,CrouchWalkLeft
			,Roll
			,Slide
			,TurnAround
			,Falling
			,Dash
		};

class	Knight
{
	public:
		Knight(sf::Vector2f position);
		~Knight();
		void	draw(sf::RenderWindow& window);
		void	eventUpdate(sf::Event& SystemEvent);
		void	HandleInput(sf::Event& SystemEvent);
		void	update(sf::RenderWindow& window);
		void	SetState(State newState);

	private:
		std::vector<sf::Texture>	textures;
		sf::Texture					_idle;
		sf::Texture					_Jump2;
		sf::Texture					_Left;
		sf::Texture					_Right;
		sf::Texture					_Attack;
		sf::Texture					_Crouch;
		sf::Texture					_CrouchAttack;
		sf::Texture					_CrouchWalkRight;
		sf::Texture					_CrouchWalkLeft;
		sf::Texture					_Roll;
		sf::Texture					_Slide;
		sf::Texture					_TurnAround;
		sf::Texture					_Falling;
		sf::Texture					_Dash;

		sf::Sprite					playerSprite;
		sf::IntRect					Rect;
		sf::Vector2f				Position;
		sf::Vector2f				Velocity;
		sf::Clock					clock;
		int							currentFrame;
		int							currentState = Idle;

		bool						isMovingLeft;
		bool						isMovingRight;
		bool						isCrouch;
		bool						isCrouchMovingLeft;
		bool						isCrouchMovingRight;
		bool						isMoving;
		bool						isLeftRight;
		bool						isJumping;
		bool						isSlide;
		bool						isTurn;
		bool						isAttack;
		bool						isRoll;
		bool						isFalling;
		bool						isDash;

		float	frameDuration 		= 0.1f;
		int		totalFrames			= 10;
		sf::Keyboard::Key			lastKeyPressed;
		sf::Clock					keyPressClock;
		float 						movementDuration = 0.01f;
		void						initTexture();
};
