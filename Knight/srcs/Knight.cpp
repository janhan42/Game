/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:48:44 by janhan            #+#    #+#             */
/*   Updated: 2024/01/08 16:26:50 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Knight.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"

int	Keystatus = 0;
float frameDuration = 0.05f; // 각 프레임을 0.1초 동안 표시
int currentFrame = 0;

bool moving = false;

void	PressedHandle(sf::Event& event, Player& player, KeyInfo& KeyInfo)
{

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::A && !moving) {
			Keystatus = player.Left;
			KeyInfo.Left = true;
			moving = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			std::cout << "Pressed A" << std::endl;
		} else if (event.key.code == sf::Keyboard::D && !moving) {
			Keystatus = player.Right;
			moving = true;
			KeyInfo.Right = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			std::cout << "Pressed D" << std::endl;
		} else if (event.key.code == sf::Keyboard::S)
		{
			Keystatus = player.Crouch;
			KeyInfo.Crouch = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			std::cout << "Pressed S" << std::endl;
		} else if (event.key.code == sf::Keyboard::W && !moving)
		{
			Keystatus = player.Jump;
			KeyInfo.Jump = true;
			moving = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			std::cout << "Pressed W" << std::endl;
		} else if (event.key.code == sf::Keyboard::Space && !moving && !KeyInfo.Attack)
		{
			Keystatus = player.Roll;
			KeyInfo.Roll = true;
			moving = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			std::cout << "Pressed Space" << std::endl;
		} else if (event.key.code == sf::Keyboard::R && !moving)
		{
			Keystatus = player.Death;
			KeyInfo.Death = true;
			moving = true;
			KeyInfo.Attack = false;
			currentFrame = 0;
			std::cout << "Pressed Space" << std::endl;
		}
	}
	else if (event.type == sf::Event::MouseButtonPressed && !moving) {
		if (event.MouseLeft) {
			Keystatus = player.Attack;
			KeyInfo.Attack = true;
			moving = true;
			currentFrame = 0;
			std::cout << "Pressed Mouse Left" << std::endl;
		}
	}
}

void	ReleasedHandle(sf::Event& event, Player& player, KeyInfo& KeyInfo)
{
	if (event.type == sf::Event::KeyReleased)
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
		} else if (event.key.code == sf::Keyboard::W)
		{
			Keystatus = player.Jump;
			KeyInfo.Jump = false;
			KeyInfo.Attack = false;
			moving = false;
		} else if (event.key.code == sf::Keyboard::R)
		{
			Keystatus = player.Death;
			KeyInfo.Death = false;
			moving = false;
		}
		if (event.key.code == sf::Keyboard::Space)
		{
			Keystatus = player.Roll;
			KeyInfo.Attack = false;
		}
	}
}

void	update(sf::Sprite& playerSprite, Player& player, KeyInfo& KeyInfo, sf::Clock& clock)
{
	if (KeyInfo.Left && !KeyInfo.Attack && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Left));
	}
	if (KeyInfo.Right && !KeyInfo.Attack &&!KeyInfo.Left && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Right));
	}
	if (KeyInfo.Crouch && !KeyInfo.Attack &&!KeyInfo.Left && !KeyInfo.Right && !KeyInfo.Jump && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Crouch));
	}
	if (KeyInfo.Jump && !KeyInfo.Attack &&!KeyInfo.Left && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Jump));
	}
	if ( KeyInfo.Roll && !KeyInfo.Attack &&!KeyInfo.Left && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Roll));
	}
	if (!KeyInfo.Attack && !KeyInfo.Left && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Death));
	}
	if (KeyInfo.Attack && !KeyInfo.Left && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Attack));
	}
	if (!KeyInfo.Attack && !KeyInfo.Left && !KeyInfo.Right && !KeyInfo.Crouch && !KeyInfo.Jump && !KeyInfo.Roll && !KeyInfo.Death) {
		playerSprite.setTexture(player.getTexture(player.Idle));
	}
}

int main(void)
{
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(150, 150), "Knight");
	window.setFramerateLimit(60);
	Player player;
	sf::Sprite playerSprite;
	KeyInfo KeyInfo;
	playerSprite.setPosition(75, 75);
	playerSprite.setTexture(player.getTexture(player.Idle));
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			// else if (event.type == sf::Event::Resized) {
			// 	sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			// 	window.setView(sf::View(visibleArea));
			// }

			if (event.type == sf::Event::KeyPressed) {
				PressedHandle(event, player, KeyInfo);
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				PressedHandle(event, player, KeyInfo);
			}
			if (event.type == sf::Event::KeyReleased) {
				ReleasedHandle(event,player,KeyInfo);
			}
		}
		update(playerSprite, player, KeyInfo, clock);
		playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
		sf::Texture sample = player.getTexture(Keystatus);
		int totalFrames = sample.getSize().x / 120;
		if (clock.getElapsedTime().asSeconds() > frameDuration) {
			currentFrame = (currentFrame + 1) % totalFrames;
			std::cout << "img.W : " << sample.getSize().x << std::endl;
			std::cout << "currentFrame : " << currentFrame << std::endl;
			std::cout << "totalFrame before : " << totalFrames << std::endl;
			if (KeyInfo.Crouch) {
					currentFrame = 2;
			}
			if (KeyInfo.Attack) {
				if (currentFrame == (sample.getSize().x / 120) - 1) {
					KeyInfo.Attack = false;
					moving = false;
					Keystatus = player.Idle;
				}
			}
			if (KeyInfo.Roll) {
				if (currentFrame == (sample.getSize().x / 120) - 1) {
					currentFrame = 0;
					KeyInfo.Roll = false;
					Keystatus = player.Idle;
					std::cout << "totalFrame after: " << totalFrames << std::endl;
					std::cout << "KeyInfo.Roll : " << KeyInfo.Roll << std::endl;
					moving = false;
				}
			}
			if (currentFrame >= sample.getSize().x / 120 && !KeyInfo.Crouch) {
				currentFrame = 0;
			}
			sf::IntRect frameRect(120 * currentFrame, 0, 120, 80);
			playerSprite.setTextureRect(frameRect);
			clock.restart(); // 시간 초기화
		}
		window.clear();
		window.draw(playerSprite);
		window.display();
	}
}

