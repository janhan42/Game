/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:16:18 by janhan            #+#    #+#             */
/*   Updated: 2023/12/20 18:51:12 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <SFML/Graphics.hpp>
#include <random>
#include <regex>
#include "PatycleSource.hpp"
#include "GravitySource.hpp"
#include "Gui.hpp"

// random RGB value
sf::Color map_val_to_color(float value)
{
	int r = 0, g = 0, b = 0;

	if (value < 0.0f) value = 0;
	if (value > 1.0f) value = 1;
	if (value < 0.5f)
	{
		b = 255 * (1.0f - 2 * value);
		g = 255 *  2 * value;
	}
	else {
		g = 255 * (2.0f - 2 * value);
		r = 255 * (2 * value - 1);
	}
	return (sf::Color(r, g, b));
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "PlanetGravity"); // 윈도우 사이즈 이름
	window.setFramerateLimit(60); // 윈도우 프레임 설정
	std::vector<GravitySource> gravityPoint; // vector 값으로 중럭 포인터 생성
	std::vector<PatycleSource> particle;
	UI buttontext(sf::Vector2f(100,100), sf::Vector2f(300, 50), std::string("size up"));

	int num_particle = 2000; // 초기 파티클 개수
// vector 를 사용해서 새로운 중력 포인터 두개 생성
	gravityPoint.push_back(GravitySource((window.getSize().x / 2.f), (window.getSize().y / 2.f), 7000));

	for (int i = 0; i < num_particle; i++) // 초기 파티클 색상 및 위치 설정
	{
		float val = (float)i / (float)num_particle;
		sf::Color col = map_val_to_color(val);
		particle.push_back(PatycleSource(600, 700, 4, 0.2 + (0.1 / num_particle) * i, col));
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) // 이벤트 관리
		{
			if (event.type == sf::Event::Closed) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // 마우스 Left 클릭으로 새로운 파티클 생성
			{
				sf::Color randomColor(std::rand() % 256, std::rand() % 256, std::rand() % 256);
				particle.push_back(PatycleSource(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y,4.0f,3.0f, randomColor));
				if(buttontext.isMouseOver(window))
				{
					for(int i = 0; i < particle.size(); i++)
					{
						particle[i].setSize();
					}
				}
				else if (gravityPoint[0].isMouseOver(window))
				{
					gravityPoint[0].isMouseEvent(window);
				}
			}
		}
		window.clear(); // 윈도우 지우기

		// 파티클 추적 및 업데이트
		for (int i = 0; i < gravityPoint.size(); i++){
			for(int j = 0;  j < particle.size(); j++)
				particle[j].update_physics(gravityPoint[i]);
		}
		for (int i = 0; i < gravityPoint.size(); i++)
			gravityPoint[i].render(window);
		for(int j = 0;  j < particle.size(); j++)
			particle[j].render(window);
		buttontext.draw(window);
		window.display();
	}
	return (0);
}
