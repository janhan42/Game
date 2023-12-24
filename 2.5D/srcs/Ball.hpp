/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ball.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 01:03:56 by janhan            #+#    #+#             */
/*   Updated: 2023/12/24 18:40:14 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

struct MouseState
{
    bool bPressed;
    bool bReleased;
    bool bHeld;
};

class Ball
{
	public:
		Ball(float pos_x, float pos_y);
		void			setColor(sf::Color color);
		void			setVelocity(sf::Vector2f vel);
		void			setPosition(sf::Vector2f pos);
		void			setStartPoint(sf::RenderWindow& window);
		void			setEndPoint(sf::RenderWindow& window);
		void			onUserCreate(std::vector<Ball> vecBall, sf::RenderWindow& window);
		sf::Vector2f	getPosition();
		float			getRadius();
		sf::Vector2f	getVelocity();
		float			getMass();
		void			draw(sf::RenderWindow& window);
		void			updatePhysics(std::vector<Ball>& vecBall, sf::RenderWindow& window);
		float			dotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2);
		void			renderTrajectory(sf::RenderWindow& window);
		 void			isMouseEvent(std::vector<Ball>& vecBalls, float mouseX, float mouseY, MouseState& m_mouse);
	private:
		sf::Vector2f	pos;
		sf::Vector2f	vel;
		sf::CircleShape	ball;
		sf::Color		color;
		sf::Vector2f	startPoint;
		sf::Vector2f	endPoint;
		sf::Vector2f	gravity{0.0f, 0.0f};
		float			mass;
		float			dt;
		Ball* pSelectedBall;
};
