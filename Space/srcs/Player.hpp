/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:27:51 by janhan            #+#    #+#             */
/*   Updated: 2023/12/19 23:41:30 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>

class Player
{
	public:
		Player(float x, float y);

		void	processEvents(sf::Keyboard::Key key, bool checkPressed);
		void	update(float deltaTime);
		void	applyGravity(float deltaTime);
		void	limitToScreenBounds();
		void	drawTo(sf::RenderWindow &window);
		void	jump();
	private:
		sf::RectangleShape rect;
		bool isUp;
		bool isDown;
		bool isLeft;
		bool isRight;
		bool isJumping;
		float velcityY;
		const float gravity;
};
