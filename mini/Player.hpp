#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <SFML/Graphics.hpp>



class Player
{
	public:
		Player(float x, float y)
		{
			rect.setSize(sf::Vector2f(x, y));
			up = false;
			down = false;
			left = false;
			right = false;
		}

		void	processEvents(sf::Keyboard::Key key, bool checkPressed)
		{
			if (checkPressed == true)
			{
				if (key == sf::Keyboard::W)
					up = true;
				if (key == sf::Keyboard::S)
					down = true;
				if (key == sf::Keyboard::A)
					left = true;
				if (key == sf::Keyboard::D)
					right = true;
			}
			if (checkPressed == false)
			{
				up = false;
				down = false;
				left = false;
				right = false;
			}
		}
		void	update()
		{
			sf::Vector2f movement;
			if (up)
				movement.y += 1.0;
			if (down)
				movement.y -= 1.0;
			if (left)
				movement.x -= 1.0;
			if (right)
				movement.x += 1.0;
			rect.move(movement);
		}

		void	drawTo(sf::RenderWindow &window)
		{
			window.draw(rect);
		}
	private:
	sf::RectangleShape rect;
	struct movement
	{
		float x;
		float y;
	};
	bool up;
	bool down;
	bool left;
	bool right;
};
