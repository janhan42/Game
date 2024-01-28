/**
 * @file System.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include "Player.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <pthread.h>

class System
{
	public:
		System(const sf::Vector2u& windowSize, const std::string& title);
		bool	isOpen();
		void	clear();
		void	display();
		void	event();

	private:
		sf::RenderWindow	_window;
		sf::Event			_event;
		Knight				_player;
		sf::Clock			clock;
		void	_close();
};
