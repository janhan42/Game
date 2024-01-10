/**
 * @file System.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Knight.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/VideoMode.hpp"

System::System(const sf::Vector2u& windowSize, const std::string& title)
: _window(sf::VideoMode(windowSize.x, windowSize.y), title)
, _player(sf::Vector2f(static_cast<float>(windowSize.x) / 2, static_cast<float>(windowSize.y) / 2))
{
	_window.setFramerateLimit(60);
}

bool	System::isOpen()
{
	return _window.isOpen();
}

void	System::_close()
{
	if (_event.type == sf::Event::Closed || _event.key.code == sf::Keyboard::Escape)
		_window.close();
	else if (_event.type == sf::Event::Resized) {
		sf::FloatRect visibleArea(0, 0, _event.size.width, _event.size.height);
		_window.setView(sf::View(visibleArea));
	}
}

void	System::event()
{
	while (_window.pollEvent(_event))
	{

		_player.HandleInput(_event);
		_close();
	}
}

void	System::clear()
{
	_window.clear();
}

void	System::display()
{
	_player.update(_window);
	_player.draw(_window);
	_window.display();
}
