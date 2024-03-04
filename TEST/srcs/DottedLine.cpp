/**
 * @file DottedLine.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "DottedLine.hpp"

DottedLine::DottedLine
(float screenWidth, float screenHeight, float lineWidth, float dotHeight, float dotSpacing, sf::Color color)
:screenWidth(screenWidth),
 screenHeight(screenHeight),
 lineWidth(lineWidth),
 dotHeight(dotHeight),
 dotSpacing(dotSpacing),
 color(color)
{
	createDots();
}

void DottedLine::createDots()
{
	float xPosition = screenWidth / 2 - lineWidth / 2;
	for (float yPosition = 0; yPosition < screenHeight; yPosition += dotHeight + dotSpacing) {
		sf::RectangleShape dot(sf::Vector2f(lineWidth, dotHeight));
		dot.setPosition(xPosition, yPosition);
		dot.setFillColor(color);
		dots.push_back(dot);
	}
}

void DottedLine::draw(sf::RenderWindow& window)
{
	for (auto& dot : dots) {
		window.draw(dot);
	}
}

