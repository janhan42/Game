/**
 * @file Player.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Player.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/InputStream.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <atomic>
#include <charconv>
#include <cmath>
#include <iostream>
#include <ostream>

float Scale = 3.0f;

Knight::Knight(sf::Vector2f position)
:	Velocity(0.0f, 0.0f)
,	Rect(120 * 0, 0, 120, 80)
{
	isMoving			= false;
	isJumping			= false;
	isTurn				= false;
	isMovingLeft 		= false;
	isMovingRight 		= false;
	isCrouchMovingLeft 	= false;
	isCrouchMovingRight = false;
	isCrouch 			= false;
	isSlide 			= false;
	isAttack 			= false;
	isRoll 				= false;
	isFalling 			= false;
	isDash 				= false;
	isLeftRight			= true;

	this->Position = position;
	currentFrame = 0;
	totalFrames = 10;
	initTexture();
	playerSprite.setTexture(textures[Idle]);
	playerSprite.setPosition(position);
	playerSprite.setTextureRect(Rect);
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height /2);
	playerSprite.setScale(Scale, Scale);
}

Knight::~Knight()
{
	textures.clear();
}

void Knight::SetState(State newState) {
	currentState = newState;

	// 상태에 따른 추가 작업
	switch (newState) {
		case Idle:
			playerSprite.setTexture(textures[Idle]);
			frameDuration	= 0.1f;
			totalFrames 	= 10;
			Velocity = {0.0f, 0.0f};
			break;
		case Left:
			playerSprite.setTexture(textures[Left]);
			playerSprite.setScale(-Scale, Scale);
			frameDuration = 0.07f;
			totalFrames = 10;
			Velocity.x = -10.f;
			if (!isMoving)
				currentFrame = 0;
			isMovingLeft = true;
			isMovingRight = false;
			isLeftRight = false;
			break;
		case Right:
			playerSprite.setTexture(textures[Right]);
			playerSprite.setScale(Scale, Scale);
			frameDuration = 0.07f;
			totalFrames = 10;
			Velocity.x = 10.f;
			if (!isMoving)
				currentFrame = 0;
			isMovingRight = true;
			isMovingLeft = false;
			isLeftRight = true;
			break;
		case Attack:
			playerSprite.setTexture(textures[Attack]);
			frameDuration = 0.05f;
			totalFrames = 10;
			if (!isAttack)
				currentFrame = 0;
			isAttack = true;
			if (!isJumping)
				Velocity.x = 0;
			break;
		case Jump:
			playerSprite.setTexture(textures[Jump]);
			frameDuration = 0.1f;
			totalFrames = 5;
			if (!isJumping)
				currentFrame = 0;
			isJumping = true;
			break;
		case Crouch:
			playerSprite.setTexture(textures[Crouch]);
			frameDuration = 0.07f;
			totalFrames = 1;
			Velocity = {0.0f, 0.0f};
			if (!isCrouch && !isMoving)
				currentFrame = 0;
			isCrouch = true;
			break;
		case CrouchAttack:
			playerSprite.setTexture(textures[CrouchAttack]);
			frameDuration = 0.1f;
			totalFrames = 4;
			if (!isAttack)
				currentFrame = 0;
			isAttack = true;
			if (!isJumping)
				Velocity.x = 0;
			break;
		case CrouchWalkRight:
			playerSprite.setTexture(textures[CrouchWalkRight]);
			playerSprite.setScale(Scale, Scale);
			frameDuration = 0.078f;
			totalFrames = 8;
			Velocity.x = 5.f;
			if (!isMoving)
				currentFrame = 0;
			isCrouchMovingRight = true;
			isLeftRight = true;
			break;
		case CrouchWalkLeft:
			playerSprite.setTexture(textures[CrouchWalkLeft]);
			playerSprite.setScale(-Scale, Scale);
			frameDuration = 0.078f;
			totalFrames = 8;
			Velocity.x = -5.f;
			if (!isMoving)
				currentFrame = 0;
			isCrouchMovingLeft = true;
			isLeftRight = false;
			break;
		case Roll:
			playerSprite.setTexture(textures[Roll]);
			frameDuration = 0.07f;
			totalFrames = 10;
			if (!isRoll)
				currentFrame = 0;
			isRoll = true;
			break;
		case Slide:
			playerSprite.setTexture(textures[Slide]);
			frameDuration = 0.2f;
			totalFrames = 4;
			if (!isSlide)
				currentFrame = 0;
			isSlide = true;
			break;
		case TurnAround:
			playerSprite.setTexture(textures[TurnAround]);
			frameDuration = 0.07f;
			totalFrames = 3;
			if (!isTurn)
				currentFrame = 0;
			isTurn	= true;
			break;
		case Falling:
			playerSprite.setTexture(textures[Falling]);
			frameDuration = 0.25;
			totalFrames = 3;
			if (isJumping)
			break;
		case Dash:
			playerSprite.setTexture(textures[Dash]);
			frameDuration = 0.1f;
			totalFrames = 2;
			if (!isDash)
				currentFrame = 0;
			isDash = true;
			break;
		// ... 기타 상태에 대한 처리 ...
	}
}

void Knight::HandleInput(sf::Event& SystemEvent)
{
	/*--------Pressed--------*/
	if (SystemEvent.type == SystemEvent.KeyPressed)
	{
		isMoving = true;
		if (SystemEvent.key.code == sf::Keyboard::D && !isSlide && !isAttack && !isRoll && !isSlide && !isDash) {

			if (!isJumping)
			{
				if (isCrouch) {
					SetState(CrouchWalkRight);
				} else if (currentState ==  Left) {
					SetState(TurnAround);
				} else if (!isTurn) {
					SetState(Right);
				}
			}
		}

		if (SystemEvent.key.code == sf::Keyboard::A && !isSlide && !isAttack && !isRoll && !isSlide && !isDash) {
			if (!isJumping) {
				if (isCrouch) {
					SetState(CrouchWalkLeft);
				} else if (currentState == Right) {
					SetState(TurnAround);
				}  else if (!isTurn) {
					SetState(Left);
				}
			}
		}
		if (SystemEvent.key.code == sf::Keyboard::W && !isJumping && !isRoll){
			SetState(Jump);
		}
		if (SystemEvent.key.code == sf::Keyboard::LShift && !isJumping && !isSlide && !isAttack && !isRoll){
			if (!isLeftRight)
				Velocity.x = -20.0f;
			else if (isLeftRight)
				Velocity.x = 20.0f;
			SetState(Slide);
		}

		if (SystemEvent.key.code == sf::Keyboard::Space && !isJumping && !isRoll && !isAttack) {
			if (!isLeftRight)
				Velocity.x = -15.0f;
			else if (isLeftRight)
				Velocity.x = 15.0f;
			SetState(Roll);
		}

		if (SystemEvent.key.code == sf::Keyboard::S && !isJumping && !isSlide && !isAttack && !isRoll && !isJumping) {
			if (isMovingLeft && !isCrouch) {
				SetState(CrouchWalkLeft);
			} else if (isMovingRight && !isCrouch) {
				SetState(CrouchWalkRight);
			} else if (!isMovingLeft && !isMovingRight) {
				SetState(Crouch);
			}
		}
	keyPressClock.restart();
	}

	if (SystemEvent.type == SystemEvent.MouseButtonPressed)
	{
		if (SystemEvent.MouseLeft && !isRoll)
		{
			if (isCrouch || isCrouchMovingLeft || isCrouchMovingRight)
				SetState(CrouchAttack);
			else
				SetState(Attack);
		}
	}
	/*--------Relesed--------*/
	if (SystemEvent.type == SystemEvent.KeyReleased)
	{
		if (SystemEvent.key.code == sf::Keyboard::D){
			if (isCrouch)
			{
				SetState(Crouch);
			}
			isMovingRight = false;
			isCrouchMovingRight = false;
		}
		if (SystemEvent.key.code == sf::Keyboard::A){
			if (isCrouch)
			{
				SetState(Crouch);
			}
			isMovingLeft = false;
			isCrouchMovingLeft = false;
		}
		if (SystemEvent.key.code == sf::Keyboard::S){
			if (isMovingLeft) {
				SetState(Left);
			} else if (isMovingRight) {
				SetState(Right);
			} else {
				SetState(Idle);
			}
			isCrouch = false;
			isCrouchMovingLeft = false;
			isCrouchMovingRight = false;
		}
	}
}

void	Knight::update(sf::RenderWindow& _window)
{
	isMoving = isMovingLeft
	|| isMovingRight
	|| isCrouch
	|| isCrouchMovingLeft
	|| isCrouchMovingRight
	|| isJumping
	|| isSlide
	|| isAttack
	|| isRoll
	|| isTurn;
	if (!isMoving && currentState != Idle)
	{
		SetState(Idle);
	}
	std::cout << "isCrouch : " << isCrouch << " " << "isCrouchMovingLeft : " << isCrouchMovingLeft << " " << "isCrouchMovingRight : " << isCrouchMovingRight <<  std::endl;
	std::cout << "isTurn : " << isTurn
	<< " " << "isLeftRight : " << isLeftRight
	<< " " << "isMoving : " << isMoving
	<< " " << "isJumping : " << isJumping
	<< " " << "isSlide : " << isSlide
	<< " " << "isRoll : " << isRoll
	<< std::endl;
	std::cout << "totalFrames : " << totalFrames << " " << "currenFrame : "<< currentFrame << " " << "currentState : " << currentState << " " << "frameDuration : " << frameDuration << std::endl;

	if (clock.getElapsedTime().asSeconds() > frameDuration) {
			currentFrame = currentFrame + 1 % totalFrames;
		if (currentFrame >= totalFrames)
			currentFrame = 0;
		clock.restart();
	}
	sf::IntRect newRect(120 * currentFrame, 0, 120, 80);
	playerSprite.setTextureRect(newRect);
	if (isJumping && !isFalling)
	{
		Velocity.y = -10.8f;
	} else if (isTurn) {
		if (currentFrame >= 0)
			frameDuration = 0.5f;
		if (currentFrame >= 1)
			frameDuration = 0.1f;
		if (!isLeftRight) {
			Velocity.x = Velocity.x * 0.9f;
		} else if (isLeftRight) {
			Velocity.x = Velocity.x * 0.9f;
		}
	} else {
		Velocity.y = 9.8f;
	}
	Position += Velocity;
	if (Position.x < 0) Position.x = 0;
	if (Position.x > _window.getSize().x) Position.x = _window.getSize().x;
	if (Position.y > _window.getSize().y - 40 * Scale) {
		Position.y = _window.getSize().y - 40 * Scale;
		if (isJumping) {
			isFalling = false;
			isJumping = false;
			if (isMovingLeft) {
				SetState(Left);
			} else if (isMovingRight) {
				SetState(Right);
			} else {
				SetState(Idle);
			}
		}
	}
	std::cout << "Player.x : " << playerSprite.getPosition().x
	<< " " << "Player.y : " << playerSprite.getPosition().y
	<< std::endl;
	playerSprite.setPosition(Position);
}

void	Knight::draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
}

void	Knight::initTexture()
{
	_idle.loadFromFile("srcs/texture/_Idle.png");
	_Jump2.loadFromFile("srcs/texture/_Jump2.png");
	_Left.loadFromFile("srcs/texture/_Run.png");
	_Right.loadFromFile("srcs/texture/_Run.png");
	_Attack.loadFromFile("srcs/texture/_AttackCombo.png");
	_Crouch.loadFromFile("srcs/texture/_CrouchWalk.png");
	_CrouchAttack.loadFromFile("srcs/texture/_CrouchAttack.png");
	_CrouchWalkRight.loadFromFile("srcs/texture/_CrouchWalk.png");
	_CrouchWalkLeft.loadFromFile("srcs/texture/_CrouchWalk.png");
	_Roll.loadFromFile("srcs/texture/_Roll.png");
	_Slide.loadFromFile("srcs/texture/_SlideAll.png");
	_TurnAround.loadFromFile("srcs/texture/_TurnAround.png");
	_Falling.loadFromFile("srcs/texture/_Fall.png");
	_Dash.loadFromFile("srcs/texture/_Dash.png");

	textures.push_back(_idle);
	textures.push_back(_Jump2);
	textures.push_back(_Left);
	textures.push_back(_Right);
	textures.push_back(_Attack);
	textures.push_back(_Crouch);
	textures.push_back(_CrouchAttack);
	textures.push_back(_CrouchWalkRight);
	textures.push_back(_CrouchWalkLeft);
	textures.push_back(_Roll);
	textures.push_back(_Slide);
	textures.push_back(_TurnAround);
	textures.push_back(_Falling);
	textures.push_back(_Dash);
}
