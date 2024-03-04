/**
 * @file PlayerStick.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <SFML/Graphics.hpp>
#include <random>

#pragma once
class PlayerStick : public sf::Drawable
{
	public:
		PlayerStick(float x, float y, float width, float height, float speed);
		sf::RectangleShape	Stick;
		void	moveUp(float deltaTime);
		void	moveDown(float deltaTime);
		void 	draw(sf::RenderWindow& window);
		void	Ai(float deltaTime, sf::RenderWindow& window, sf::Vector2f BallPos);
		virtual void	update(sf::Event& event, float deltaTime) = 0;
	private:
		float				Speed;
		protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		target.draw(Stick, states);
	}
};
