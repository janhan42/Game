/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:24:41 by janhan            #+#    #+#             */
/*   Updated: 2024/05/07 09:20:44 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PLAYER_HPP
# define PLAYER_HPP
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <SFML/Graphics.hpp>

class Player
{
	public:
		Player(float px, float py);
		~Player();
		void			drawRays3d(sf::RenderWindow &window);
		void			_press_buttons(sf::Keyboard::Key key);
		void			drawMap2D(sf::RenderWindow &widnow);
		void			_set_Position(float px, float py);
		sf::Vector2f	_get_Position();
		void			draw(sf::RenderWindow &window);
	private:
		sf::CircleShape Player_Body;
		float px;
		float py;
		float p_deltax;
		float p_deltay;
		float p_angel;
};

#endif
