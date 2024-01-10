/**
 * @file Knight.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Knight.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "System.hpp"

sf::Vector2u	windowSize(1000.f, 1000.f);

int main(void)
{
	System system(windowSize, "Knight");

	while (system.isOpen())
	{
		system.event();
		system.clear();
		system.display();
	}
	return (0);
}
