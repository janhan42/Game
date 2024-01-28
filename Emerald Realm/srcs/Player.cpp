/**
 * @file Player.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include "Player.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include <functional>

Player::Player(int totalFrame)
{
	/* 임시 */
	_textuer.loadFromFile("sprite/player.png");
	/* --- */
	this->Action = new bool[totalFrame];
	this->frameMax = new int[totalFrame];
	this->movement = new sf::Vector2f[totalFrame];
	this->_healthPoints		= 100;
	this->_stamina 			= 100;
	this->cur				= idleDown;
	this->revers			= false;
}

Player::~Player()
{
	delete[] Action;
	delete [] frameMax;
	delete [] movement;
}

/* ======= InPut ======== */
void	Player::inPut(int keyCode, int type)
{
	if (type == Player::PRESSED)
	{
		if (keyCode == sf::Keyboard::W)
		{
			Action[moveUp] = true;
			(cur < 3)
				setCur(moveUp);
		}
		if (keyCode == sf::Keyboard::A)
		{
			Action[move]	= true;
			revers			= false;
			(cur < 3)
				cur = move;
		}
		if (keyCode == sf::Keyboard::S)
		{
			Action[moveDown] = true;
			(cur < 3)
				cur = moveDown;
		}
		if (keyCode == sf::Keyboard::D)
		{
			Action[move]	= true;
			revers			= true;
			(cur < 3)
				cur = move;
		}
	}
	if (type == Player::RELEASED)
	{
		if (keyCode == sf::Keyboard::W)
		{
			Action[moveUp] = false;
		}
		if (keyCode == sf::Keyboard::A)
		{
			Action[move]	= false;
		}
		if (keyCode == sf::Keyboard::S)
		{
			Action[moveDown] = false;
			updown = 0;
		}
		if (keyCode == sf::Keyboard::D)
		{
			Action[move]	= false;
		}
	}
}

void	Player::setPosition(sf::Vector2f Accelation)
{
	std::cout << "setNewPositon" << std::endl;
	sf::Vector2f pos = getPosition();
	pos += Accelation;
	_sprite.setPosition(pos);
}
/* =========== UPDATE =========== */
void	Player::setSprite()
{
	if ()
}

void	Player::upDate()
{

}
// 캔슬 가능 동작과 불가능 동작
// 나는 조건문을 거의 안쓰고 대신 curActiom. cancle <= int 변수 emum Idle = 0, Left = 1
// 입력이 들어오면 캔슬 가능 동작은 걍 cur, 불가능은 cancle
// 만약에 setAction() -> cancle이 없어야만 cur를 수행하고 / cur 그냥 무시
// cur는 릴리즈 당시에 값을 삭제 , cnacle은 입력 이후에 전체 프레임으 ㄹ 돌고 거기서 삭제해
/* ========= GET ======== */

sf::Vector2f	Player::getPosition()
{
	return this->_sprite.getPosition();
}

float	Player::getHealthPoint()
{
	return this->_healthPoints;
}

float			Player::getStamina()
{
	return this->_stamina;
}

sf::Sprite	Player::getSprite()
{
	return this->_sprite;
}

/* ====== SET ====== */

void	Player::setHealthPoint(float	newHealthPoint)
{
	this->_healthPoints = newHealthPoint;
}

void	Player::setStamina(float	newStamina)
{
	this->_stamina = newStamina;
}



