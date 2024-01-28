/**
 * @file system.hpp
 * @author jang hun han (janhan@student.42Seoul.kr)
 * @brief
 * @version 0.1
 * @date 2024-01-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
# include "core.hpp"

class	System
{
	public:
		System();
		bool	isOpen();
		void	hook();
		void	update();
	private:
		sf::RenderWindow	_window;
		sf::Event			_event;
		bool				state;
};
