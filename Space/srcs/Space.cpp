/**
 * @file Space.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Space.hpp"
#include "Planet.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <vector>

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "SPACE");
	/* 메인 화면뷰 와 미니맵 뷰 */
	sf::View mainMap(sf::FloatRect(0.0f, 0.0f, SCREEN_W, SCREEN_H));
	sf::View miniMap = mainMap;
	std::vector<Planet> planets;
	Planet moon(sf::Vector2f(500, 500), 10, 9.8);

	window.setFramerateLimit(60);
	miniMap.zoom(2.0f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();

			/* ------- 이벤트 처리 ------- */

		}
		/* 오브젝트 업데이트 */
		window.clear();
		window.setView(mainMap);
		/* 오브젝트 렌더링 */
		moon.Draw(window);

		/* 미니 맵 렌더링 */
		window.setView(miniMap);
		moon.Draw(window);
		window.display();
	}
}
