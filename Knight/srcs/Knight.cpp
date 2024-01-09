/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:48:44 by janhan            #+#    #+#             */
/*   Updated: 2024/01/09 12:36:52 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Knight.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include <locale>
#include <regex>
#include <sys/errno.h>

int	Keystatus = 0;
float frameDuration = 0.05f; // 각 프레임을 0.1초 동안 표시
int currentFrame = 0;
int totalFrames = 0;
bool moving = false;
bool isLeftRight = false;
bool isRoll = false;
float	Scale = 3.0f;

void	PressedHandle(sf::Event& event, Player& player, KeyInfo& KeyInfo)
{

	if (event.type == sf::Event::KeyPressed)
	{
		std::cout << "event.key.code " << event.key.code << std::endl;
		if (event.key.code == sf::Keyboard::A && !moving) {
			Keystatus = player.Left;
			KeyInfo.Left = true;
			moving = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			isLeftRight = false;
			// std::cout << "Pressed A" << std::endl;
		} else if (event.key.code == sf::Keyboard::D && !moving) {
			Keystatus = player.Right;
			moving = true;
			KeyInfo.Right = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			isLeftRight = true;
			// std::cout << "Pressed D" << std::endl;
		} else if (event.key.code == sf::Keyboard::S)
		{
			Keystatus = player.Crouch;
			KeyInfo.Crouch = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			// std::cout << "Pressed S" << std::endl;
		} else if (event.key.code == sf::Keyboard::W && !KeyInfo.Jump && !isRoll && !KeyInfo.Roll)
		{
			Keystatus = player.Jump;
			KeyInfo.Jump = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			// std::cout << "Pressed W" << std::endl;
		} else if (event.key.code == sf::Keyboard::Space && !KeyInfo.Attack &!isRoll && !KeyInfo.Jump)
		{
			std::cout << "SPACE EVENT" << std::endl;
			Keystatus = player.Roll;
			KeyInfo.Roll = true;
			moving = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			isRoll = true;
			// std::cout << "Pressed Space" << std::endl;
		} else if (event.key.code == sf::Keyboard::R && !KeyInfo.Death)
		{
			Keystatus = player.Death;
			KeyInfo.Death = true;
			moving = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			// std::cout << "Pressed Space" << std::endl;
		}
	}

	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			Keystatus = player.Attack;
			KeyInfo.Attack = true;
			currentFrame = 0;
			// std::cout << "Pressed Mouse Left" << std::endl;
		}
	}
}

void	ReleasedHandle(sf::Event& event, Player& player, KeyInfo& KeyInfo)
{
	if (event.type == sf::Event::KeyReleased && !KeyInfo.Death)
	{
		if (event.key.code == sf::Keyboard::A) {
			Keystatus = player.Left;
			KeyInfo.Left = false;
			KeyInfo.Attack = false;
			moving = false;
		} else if (event.key.code == sf::Keyboard::D) {
			Keystatus = player.Right;
			KeyInfo.Right = false;
			KeyInfo.Attack = false;
			moving = false;
		} else if (event.key.code == sf::Keyboard::S)
		{
			Keystatus = player.Crouch;
			KeyInfo.Crouch = false;
			KeyInfo.Attack = false;
		} else if (event.key.code == sf::Keyboard::W && !isRoll && !KeyInfo.Roll)
		{
			Keystatus = player.Jump;
			KeyInfo.Attack = false;
			moving = false;
		} else if (event.key.code == sf::Keyboard::Space && !KeyInfo.Attack &!isRoll && !KeyInfo.Jump)
		{

			Keystatus = player.Roll;
			KeyInfo.Attack = false;
		}
	}
}

void	update(sf::Sprite& playerSprite, Player& player, KeyInfo& KeyInfo, sf::Clock& clock, sf::RenderWindow& window)
{
	const float gravity = 9.8f; // 중력 가속도
	static float verticalSpeed = 0.0f; // 수직 속도
	float moveSpeed = 10.0f; // 이동 속도
	sf::Vector2f currentPosition = playerSprite.getPosition();
	if (!KeyInfo.Jump) {
		verticalSpeed += gravity;
	} else {
		verticalSpeed = -5.0f; // 점프 시 수직 속도 반전
	}

	if (KeyInfo.Roll && isRoll)
	{
		std::cout << "ROLL EVENT" << std::endl;
		if (isLeftRight)
		{
			currentPosition.x += moveSpeed + 2;
		}
		if (!isLeftRight)
		{
			currentPosition.x -= moveSpeed + 2;
		}
	}

	if (KeyInfo.Left && !isRoll) {
		currentPosition.x -= moveSpeed;
	}
	if (KeyInfo.Right && !isRoll) {
		currentPosition.x += moveSpeed;
	}
	currentPosition.y += verticalSpeed;

	if (currentPosition.x < 0) currentPosition.x = 6;
	if (currentPosition.x > window.getSize().x)
		currentPosition.x = window.getSize().x - 6;
	if (currentPosition.y > window.getSize().y)
		currentPosition.y = window.getSize().y - 42 * Scale;
	playerSprite.setPosition(currentPosition);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);


	if (KeyInfo.Left && !KeyInfo.Attack && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Left));
		playerSprite.setScale(-Scale, Scale);
		totalFrames = 10;
	}
	if (KeyInfo.Right && !KeyInfo.Attack &&!KeyInfo.Left && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Right));
		playerSprite.setScale(Scale, Scale);
		totalFrames = 10;
	}
	if (KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Death ) {
		playerSprite.setTexture(player.getTexture(player.Crouch));
		totalFrames = 2;
	}
	if (KeyInfo.Jump && !KeyInfo.Attack && !KeyInfo.Left && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Jump));
		totalFrames = 5;
	}
	if (KeyInfo.Roll && !KeyInfo.Attack && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Death && !KeyInfo.Left && !KeyInfo.Right) {
		playerSprite.setTexture(player.getTexture(player.Roll));
		totalFrames = 12;
	}
	if (!KeyInfo.Attack && !KeyInfo.Left && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Death));
		totalFrames = 10;
	}
	if (KeyInfo.Attack && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Attack));
		totalFrames = 10;
	}
	if (!KeyInfo.Attack && !KeyInfo.Left && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Idle));
		totalFrames = 10;
	}
}

int main(void)
{
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(500, 500), "Knight");
	window.setFramerateLimit(60);
	Player player;
	sf::Sprite playerSprite;
	KeyInfo KeyInfo;
	playerSprite.setPosition(250, 250);
	playerSprite.setScale(Scale, Scale);
	playerSprite.setTexture(player.getTexture(player.Idle));
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::Resized) {
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
			if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed && !KeyInfo.Death)  {
				PressedHandle(event, player, KeyInfo);
			}
			if (event.type == sf::Event::KeyReleased) {
				ReleasedHandle(event,player,KeyInfo);
			}
		}
		update(playerSprite, player, KeyInfo, clock, window);
		playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
		sf::Texture sample = player.getTexture(Keystatus);
		if (clock.getElapsedTime().asSeconds() > frameDuration)
		{
			if (!KeyInfo.Left)
			{
				if (!KeyInfo.Death && !KeyInfo.Crouch)
					currentFrame = currentFrame + 1  % totalFrames;
				else if (KeyInfo.Death)
				{
					if (currentFrame != 9)
						currentFrame += 1;
				}
				else if (KeyInfo.Crouch)
				{
					if (currentFrame != totalFrames)
						currentFrame = 1;

				}
				std::cout << "curenFrame 1 : " << currentFrame << std::endl;
			}
			if (currentFrame >= totalFrames && !KeyInfo.Crouch) {
				if (KeyInfo.Roll)
				{
					KeyInfo.Roll = false;
					isRoll = false;
					totalFrames = 10;
				}
				if (KeyInfo.Attack)
				{
					KeyInfo.Attack = false;
				}
				if (KeyInfo.Jump)
				{
					KeyInfo.Jump = false;
				}
				if (!KeyInfo.Death && !KeyInfo.Crouch)
					currentFrame = 0;
				if (KeyInfo.Roll)
				{
					KeyInfo.Roll = false;
				}
				else if (KeyInfo.Death)
				{
					currentFrame = 9;
				}
				std::cout << "curenFrame 3 : " << currentFrame << std::endl;
				std::cout << "totalFrames : " << totalFrames << std::endl;
			}

			sf::IntRect frameRect(120 * currentFrame, 0, 120, 80);
			if (KeyInfo.Left)
			{
				currentFrame = currentFrame + 1  % totalFrames;
				sf::IntRect frameRect(120 * (currentFrame), 0, -120, 8);
				std::cout << "curenFrame 5 :" << currentFrame << std::endl;
			}
			playerSprite.setTextureRect(frameRect);
			clock.restart(); // 시간 초기화
		}
		window.clear();
		window.draw(playerSprite);
		window.display();
	}
}

