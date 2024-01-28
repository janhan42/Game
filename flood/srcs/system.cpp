/**
 * @file system.cpp
 * @author jang hun han (janhan@student.42Seoul.kr)
 * @brief
 * @version 0.1
 * @date 2024-01-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "system.hpp"
#include "SFML/Config.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "core.hpp"

System::System()
: _window(sf::VideoMode(SCREEN_W, SCREEN_H), "Flood fill")
, state(false)
{
	_window.setFramerateLimit(60);
}

bool	System::isOpen()
{
	if (!state)
		state = _window.isOpen();
	return (state);
}

void	System::update()
{
	_window.clear();
	/* 다른 업데이트 및 렌더 모듈 */

	_window.display();
}


