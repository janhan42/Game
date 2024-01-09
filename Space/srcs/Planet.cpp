/**
 * @file Planet.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Planet.hpp"
#include <cmath>

Planet::Planet(sf::Vector2f center, float radius, float gravityStrength)
	: center(center), radius(radius), gravityStrength(gravityStrength) {
	shape.setRadius(radius);
	shape.setOrigin(radius, radius); // 원의 중심을 중심점으로 설정
	shape.setPosition(center);
	shape.setFillColor(sf::Color::Green); // 색상은 원하는 대로 설정
}

sf::Vector2f Planet::GetGravityForce(const sf::Vector2f& objectPosition) const {
	sf::Vector2f direction = center - objectPosition;
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	float forceMagnitude = gravityStrength / (distance * distance);

	// 단위 벡터로 변환
	sf::Vector2f forceDirection = direction / distance;
	return forceDirection * forceMagnitude;
}

void Planet::Draw(sf::RenderWindow& window) const {
	window.draw(shape);
}
