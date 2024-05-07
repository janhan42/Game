/**
 * @brief
 *
 * @return float
 */

#include "Ball.hpp"
#include <algorithm>
#include <iostream>


Ball::Ball(float mX, float mY)
{
	shape.setPosition(mX, mY);
	shape.setRadius(10.f);
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	velocity = sf::Vector2f(-15.f, -15.f);
	if (!WallSound.loadFromFile("PongWall.wav"))
		std::cout << "Wall sound load Failed" << std::endl;
	if (!StickSound.loadFromFile("PongStick.wav"))
		std::cout << "Stick sound load Failed" << std::endl;
	if (!ScoreSound.loadFromFile("PongScore.wav"))
		std::cout << "Score sound load Failed" << std::endl;
}

void	Ball::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Ball::update(const PlayerStick& playerLeft, const PlayerStick& playerRight, sf::RenderWindow& window, int& Left, int& Right)
{
	if (isResetting == true)
	{
		std::cout << "Reset" << std::endl;
		std::cout << "Time " << clock.getElapsedTime().asMilliseconds() << std::endl;
		std::cout << "isResetting " << isResetting << std::endl;
		if (clock.getElapsedTime().asSeconds() >= 0.5f) {
			std::cout << "clock in" << std::endl;
			resetBall(window);
			isResetting = false; // 리셋 상태 해제
			clock.restart(); // 타이머 리셋
		}
		} else if (isResetting == false) {
			shape.move(velocity);
	}
	// 스틱과 공의 충돌 검사
	if (isResetting == false)
	{

		if (shape.getGlobalBounds().intersects(playerLeft.Stick.getGlobalBounds()) ||
			shape.getGlobalBounds().intersects(playerRight.Stick.getGlobalBounds())) {

				// 여기서 stickCenter 계산 로직 수정 필요
				float stickCenter; // 스틱의 중앙 위치 Y 좌표
				float ballCenter = shape.getPosition().y; // 공의 중앙 위치 Y 좌표

				// 충돌한 스틱을 판별하고 stickCenter 계산
				if (shape.getGlobalBounds().intersects(playerLeft.Stick.getGlobalBounds())) {
					stickCenter = playerLeft.Stick.getPosition().y + (playerLeft.Stick.getSize().y / 2);
				} else {
					stickCenter = playerRight.Stick.getPosition().y + (playerRight.Stick.getSize().y / 2);
				}
				// 충돌 지점에 따른 반사 각도 조정
				float deltaY = ballCenter - stickCenter;
				velocity.y = deltaY * 0.1f; // 반사 각도 조정, 값은 조정 가능
				// 수평 방향 반전 (스틱에 맞았으므로)
				velocity.x = -velocity.x;
				sound.setBuffer(StickSound);
				sound.play();
			}

		// 화면 경계와의 충돌 검사

		if (left() < 0)
		{
				// 리셋 시작
				Right += 1;
				isResetting = true;
				clock.restart();
				sound.setBuffer(ScoreSound);
				sound.play();
		}
		if(right() > window.getSize().x)
		{
			Left += 1;
			isResetting = true;
			clock.restart();
			sound.setBuffer(ScoreSound);
			sound.play();
		}
		if (top() < 0 || bottom() > window.getSize().y)
		{
			velocity.y = -velocity.y; // Y 방향 반전
			sound.setBuffer(WallSound);
			sound.play();
		}

	}
}

void Ball::resetBall(sf::RenderWindow& window)
{
	shape.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
	velocity.y = 0;
}

sf::Vector2f Ball::getPosition()
{
	return (this->shape.getPosition());
}

float	Ball::left() { return shape.getPosition().x - shape.getRadius(); }
float	Ball::right() { return shape.getPosition().x + shape.getRadius(); }
float	Ball::top() { return shape.getPosition().y - shape.getRadius(); }
float	Ball::bottom() { return shape.getPosition().y + shape.getRadius(); }
