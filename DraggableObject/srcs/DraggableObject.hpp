/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DraggableObject.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:52:49 by janhan            #+#    #+#             */
/*   Updated: 2023/12/24 17:56:35 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include <vector>

class DraggableObject
{
	public:
		DraggableObject();
		void			draw(sf::RenderWindow& window);
		void			render();
		void			setStartPoint(sf::RenderWindow& window);
		void			setEndPoint(sf::RenderWindow& window);
		sf::Vector2i	getStartPoint();
		sf::Vector2i	getEndPoint();
		bool			isMouseOver(const sf::RenderWindow& window);

	private:
		sf::Vector2i startPoint;
		sf::Vector2i endPoint;
		sf::RectangleShape object;
		int	id;
		bool isDrawing;

};
