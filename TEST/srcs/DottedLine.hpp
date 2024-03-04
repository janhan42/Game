/**
 * @file DottedLine.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "SFML/Graphics/Color.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class	DottedLine
{
	public:
		std::vector<sf::RectangleShape>	dots;
		float							dotHeight;
		float							dotSpacing;
		float							lineWidth;
		sf::Color						color;
		float					screenHeight;
		float					screenWidth;

		DottedLine(float screenWidth,
				float screenHeight,
				float lineWidth,
				float dotHeight,
				float dotSpacing,
				sf::Color color);
		void	createDots();
		void	draw(sf::RenderWindow& window);
	private:
};
