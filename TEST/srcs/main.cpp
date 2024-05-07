/**
 * @file main.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <random>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <SFML/Graphics.hpp>
#include "Player_Left.hpp"
#include "Player_Right.hpp"
#include "Ball.hpp"
#include "DottedLine.hpp"

bool keyinfo[4] = { false };


int	main(void)
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(1500, 1000), "PONG");
	window.setFramerateLimit(60);
	sf::Event event;
	Ball ball(750, 500);
	DottedLine	Line(window.getSize().x, window.getSize().y, 2, 10, 4, sf::Color::White);
	sf::Font font;
	sf::Text scoreTextleft;
	sf::Text scoreTextright;
	int	scoreLeft = 0;
	int	scoreRight = 0;

	font.loadFromFile("arial.ttf");
	scoreTextleft.setFont(font);
	scoreTextright.setFont(font);
	scoreTextleft.setCharacterSize(100); // 텍스트 크기
	scoreTextright.setCharacterSize(100); // 텍스트 크기
	scoreTextleft.setFillColor(sf::Color::White); // 텍스트 색상
	scoreTextright.setFillColor(sf::Color::White); // 텍스트 색상
	scoreTextleft.setPosition(650, 100); // 텍스트 위치 설정
	scoreTextright.setPosition(1000, 100); // 텍스트 위치 설정
	scoreTextleft.setOrigin(100, 100);
	scoreTextright.setOrigin(100, 100);

	Player_Left playerLeft(float(50), float(500), float(10), float(250), float(30));
	Player_Right playerRight(float(window.getSize().x - 50), float(500), float(10), float(250), float(30));
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					keyinfo[0] = true;
					if (keyinfo[1] == true)
						keyinfo[1] = false;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					keyinfo[1] = true;
					if (keyinfo[0] == true)
						keyinfo[0] = false;
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					keyinfo[2] = true;
					if (keyinfo[3] == true)
						keyinfo[3] = false;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					keyinfo[3] = true;
					if (keyinfo[2] == true)
						keyinfo[2] = false;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
					keyinfo[0] = false;
				if (event.key.code == sf::Keyboard::S)
					keyinfo[1] = false;
				if (event.key.code == sf::Keyboard::Up)
					keyinfo[2] = false;
				if (event.key.code == sf::Keyboard::Down)
					keyinfo[3] = false;
			}
		}
		if (keyinfo[0] == true)
			playerLeft.moveUp(0.5);
		if (keyinfo[1] == true)
			playerLeft.moveDown(0.5);
		if (keyinfo[2] == true)
			playerRight.moveUp(0.5);
		if (keyinfo[3] == true)
			playerRight.moveDown(0.5);
		ball.update(playerLeft, playerRight, window, scoreLeft, scoreRight);
		// playerLeft.update(event, 0.5);
		// playerRight.update(event, 0.5);
		playerRight.Ai(0.5, window, ball.getPosition());
		playerLeft.Ai(0.5, window, ball.getPosition());
		scoreTextleft.setString(std::to_string(scoreLeft));
		scoreTextright.setString(std::to_string(scoreRight));
		window.clear();
		Line.draw(window);
		playerLeft.draw(window);
		playerRight.draw(window);
		ball.draw(window);
		window.draw(scoreTextleft);
		window.draw(scoreTextright);
		window.display();
	}
}
