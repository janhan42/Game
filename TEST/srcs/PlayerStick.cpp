/**
 * @file PlayerStick.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "PlayerStick.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

PlayerStick::PlayerStick(float x, float y, float width, float height, float speed)
:	Speed(speed)
{
	Stick.setSize(sf::Vector2f(width, height));
	Stick.setPosition(sf::Vector2f(x, y));
	Stick.setFillColor(sf::Color::White);
}

void	PlayerStick::moveUp(float deltaTime)
{
	float moveAmount = -Speed * deltaTime;
	float newY = Stick.getPosition().y + moveAmount;
	if (newY < 0) {
		Stick.setPosition(Stick.getPosition().x, 0);
	} else {
		Stick.move(0, moveAmount);
	}
}

void	PlayerStick::moveDown(float deltaTime)
{
	float moveAmount = Speed * deltaTime;
	float newY = Stick.getPosition().y + moveAmount;
	float screenHeight = 1000;

	if (newY + Stick.getSize().y > screenHeight) {
		Stick.setPosition(Stick.getPosition().x, screenHeight - Stick.getSize().y);
	} else {
		Stick.move(0, moveAmount);
	}
}
#include <random>
void	PlayerStick::Ai(float deltaTime, sf::RenderWindow& window, sf::Vector2f Ballpos)
{
	if (rand() % 10 < 1)
		return ;
	float stickCenterY = this->Stick.getPosition().y + this->Stick.getSize().y / 2.0f;
    float distanceY = std::abs(Ballpos.y - stickCenterY); // Y축 거리
    float distanceX = std::abs(Ballpos.x - this->Stick.getPosition().x); // X축 거리

    // X 좌표에 따른 반응 거리 설정
   float reactionDistanceX = 750.0f;
	float reactionDistanceY = 500.0f;

	// 총 거리를 계산하여 반응 거리 내에서의 비율 계산
	float totalDistance = std::sqrt(distanceX * distanceX + distanceY * distanceY);
	float reactionRadius = std::sqrt(reactionDistanceX * reactionDistanceX + reactionDistanceY * reactionDistanceY);

	// 총 거리에 대한 반응 속도 조정 계수 계산
	float speedAdjustment = 1.0f - (totalDistance / reactionRadius);
	speedAdjustment = std::max(0.0f, speedAdjustment); // 속도 조정이 음수가 되지 않도록 함

	// 속도 조정 계수를 이용해 이동 속도 계산
	float moveSpeed = Speed * speedAdjustment + 1;
	if (distanceX < reactionDistanceX) {
		// 거리에 따른 반응 속도 조정
		float speedAdjustment = distanceX / reactionDistanceX;
		float moveSpeed = Speed * speedAdjustment;
		if (moveSpeed <= 6)
			moveSpeed = 6;
		if (Ballpos.y > stickCenterY && distanceY > this->Stick.getSize().y / 4.0f) {
			this->Stick.move(0, moveSpeed);
		} else if (Ballpos.y < stickCenterY && distanceY > this->Stick.getSize().y / 4.0f) {
			this->Stick.move(0, -moveSpeed);
		}
	}
}

void	PlayerStick::draw(sf::RenderWindow& window)
{
	window.draw(this->Stick);
}
