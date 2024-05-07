/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:26:22 by janhan            #+#    #+#             */
/*   Updated: 2024/05/07 17:30:52 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <iostream>

#define PI 3.1415926535
#define PI2 PI/2
#define PI3 3*PI/2
#define DR 0.0174533 // one defree in radians

int map[] =
{
	1,1,1,1,1,1,1,1,1,1,
	1,0,1,0,1,0,1,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,1,0,1,0,1,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,1,0,1,0,1,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,1,0,1,0,1,0,0,1,
	1,0,0,1,1,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1
};
int mapX=10,mapY=10,mapS=64;

Player::Player(float px, float py)
{
	this->px = px;
	this->py = py;
	this->p_angel= 90;
	this->p_deltax = cos(p_angel) * 5;
	this->p_deltay = sin(p_angel) * 5;
	Player_Body.setRadius(8);
	Player_Body.setFillColor(sf::Color::Green);
	Player_Body.setPosition(this->px, this->py);
	Player_Body.setOrigin(8, 8);
}

Player::~Player()
{

}

float dist(float ax, float ay, float bx, float by, float ang)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	Player::drawRays3d(sf::RenderWindow &window)
{
	int r, mx, my, mp, dof; float rx, ry, ra, xo, yo, disT;
	float pi = 3.1415926535;
	sf::Color DrawWall;

	ra = p_angel - DR * 30; // 총 60도 시야각 을 만들어야함.
	if(ra < 0)
	{
		ra += 2 * PI;
	}
	if (ra > 2 * PI)
	{
		ra -= 2 *PI;
	}
	for (r = 0; r < 1000; r++)
	{
		// ---- Check Horizontal Lines -----
		dof = 0;
		float disH = 1000000, hx = px, hy = py;
		float aTan = -1 / tan(ra);
		if (ra > PI) // looking up
		{
			ry = (((int)py >> 6) << 6) -0.0001;
			rx = (py - ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI) // looking Down
		{
			ry = (((int)py >> 6 ) << 6) + 64;
			rx = (py - ry) * aTan+px;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == pi)
		{
			rx = px;
			ry = py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * mapX + mx;
			if(mp > 0 && mp < mapX * mapY && map[mp] == 1)
			{
				hx = rx;
				hy = ry;
				disH = dist(px, py, hx, hy ,ra);
				dof = 8;
			}
			else {
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		// ---- Check Vretical Lines -----
		dof = 0;
		float disV = 1000000, vx = px, vy = py;
		float nTan = -tan(ra);
		if (ra > PI2 && ra < PI3) // looking left
		{
			rx = (((int)px >> 6) << 6) -0.0001;
			ry = (px - rx) * nTan + py;
			xo = -64;
			yo = -xo * nTan;
		}
		if (ra < PI2 || ra > PI3) // looking right
 		{
			rx = (((int)px >> 6 ) << 6) + 64;
			ry = (px - rx) * nTan + py;
			xo = 64;
			yo = -xo * nTan;
		}
		if (ra == 0 || ra == pi) // looking staright up or down
		{
			rx = px;
			ry = py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * mapX + mx;
			if(mp > 0 && mp < mapX * mapY && map[mp] == 1)
			{
				vx = rx;
				vy = ry;
				disV = dist(px, py, vx, vy ,ra);
				dof = 8;
			}
			else {
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		if (disV < disH) // vertical wall
		{
			rx = vx;
			ry = vy;
			disT = disV;
			std::cout << "disT : " << disT << std::endl;
			std::cout << "(int)disT /  : " << (int)disT / 10 << std::endl;

			DrawWall = sf::Color(117 - (int)disT / 10, 170, 255);
		}
		else if (disH < disV) // horizontal wall
		{
			rx = hx;
			ry = hy;
			disT = disH;
			DrawWall = sf::Color(91 - (int)disT / 10, 133, 201);
		}
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(px, py), sf::Color::Blue),
			sf::Vertex(sf::Vector2f(rx, ry), sf::Color::Blue)
		};
		window.draw(line, 2, sf::Lines);
		// -- Draw 3D Wall --
		float ca = p_angel - ra;
		if (ca < 0)
		{
			ca += 2 * PI;
		}
		if (ca > 2 * PI)
		{
			ca -= 2 * PI;
		}
		disT = disT * cos(ca); // fix fisheye
		float lineH = (mapS * 500) / (disT); // 벽을 만들때의 최대 길이 지정
		float lineO = 15 - lineH / 2; // 화면 중앙에 올수있게 오프셋
		std::cout << "lineO : " << lineO << std::endl;
		if (lineH > 500)
		{
			lineH = 500;
		}
		sf::RectangleShape floor(sf::Vector2f(1, 1200));
		sf::RectangleShape sealing(sf::Vector2f(1, 1200));
		sf::RectangleShape line3(sf::Vector2f(1, lineH));
		sf::RectangleShape line4(sf::Vector2f(1, lineH));
		sealing.setFillColor(sf::Color(250, 197, 82));
		floor.setFillColor(sf::Color::Yellow);
		line3.setFillColor(DrawWall);
		line4.setFillColor(DrawWall);
		sealing.setPosition(r * 1 + 650, lineO / 2);
		floor.setPosition(r * 1 + 650, lineO + 300);
		line4.setPosition(r * 1 + 650, lineO + 300);
		line3.setPosition(r * 1 + 650, lineO + lineH + 300);
		window.draw(sealing);
		window.draw(floor);
		window.draw(line3);
		window.draw(line4);
		ra += DR / 20;
		if (ra < 0)
		{
			ra += 2 * PI;
		}
		if (ra > 2 * PI)
		{
			ra -= 2 * PI;
		}
	}
}
void	Player::_press_buttons(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::A)
	{
		this->p_angel -= 0.1;
		if (this->p_angel < 0)
		{
			this->p_angel += 2 * PI;
		}
		this->p_deltax=cos(p_angel) * 5;
		this->p_deltay=sin(p_angel) * 5;
	}
	if (key == sf::Keyboard::D)
	{
		this->p_angel += 0.1;
		if (this->p_angel > 2 * PI)
		{
			this->p_angel -= 2 * PI;
		}
		this->p_deltax=cos(p_angel) * 5;
		this->p_deltay=sin(p_angel) * 5;
	}
	int xo = 0;
	if (p_deltax < 0)
	{
		xo = -20;
	}
	else
	{
		xo = 20;
	}
	int yo = 0;
	if (p_deltay < 0)
	{
		yo = -20;
	}
	else
	{
		yo = 20;
	}
	int ipx = px / 64.0, idx_add_xo = (px + xo) / 64.0, ipx_sub_xo = (px-xo)/64.0; // Wall Collision
	int ipy = py / 64.0, idy_add_yo = (py + yo) / 64.0, ipy_sub_yo = (py-yo)/64.0; // Wall Collision
	if (key == sf::Keyboard::W)
	{
		if (map[ipy * mapX + idx_add_xo] == 0)
		{
			px += p_deltax * 0.8;
		}
		if (map[idy_add_yo * mapX + ipx] == 0)
		{
			py += p_deltay * 0.8;
		}
	}
	if (key == sf::Keyboard::S)
	{
		if (map[ipy * mapX + ipx_sub_xo] == 0)
		{
			px -= p_deltax * 0.8;
		}
		if (map[ipy_sub_yo * mapX + ipx] == 0)
		{
			py -= p_deltay * 0.8;
		}
	}
	_set_Position(px, py);
}
void	Player::_set_Position(float px, float py)
{
	this->px = px;
	this->py = py;
	Player_Body.setPosition(px, py);
}

void	Player::drawMap2D(sf::RenderWindow &window)
{
	int x,y,xo,yo;
	sf::Color drawColor;
	for (y = 0; y < mapY; y++)
	{
		for (x = 0; x < mapX; x++)
		{
			if (map[y * mapX+x] == 1)
				drawColor = sf::Color::White;
			else
				drawColor = sf::Color::Black;
			xo = x * mapS;
			yo = y * mapS;
			 sf::VertexArray quad(sf::Quads, 4);
			quad[0].position = sf::Vector2f(0 + xo + 1, 0 + yo + 1);
			quad[1].position = sf::Vector2f(0 + xo + 1, mapS + yo - 1);
			quad[2].position = sf::Vector2f(mapS + xo - 1, mapS + yo - 1);
			quad[3].position = sf::Vector2f(mapS + xo - 1, 0 + yo + 1);
			// 사각형 색상 설정
			for (int i = 0; i < 4; ++i) {
				quad[i].color = drawColor; // 빨간색으로 설정
			}
			window.draw(quad);
		}
	}
}
sf::Vector2f	Player::_get_Position()
{
	return (this->Player_Body.getPosition());
}
void	Player::draw(sf::RenderWindow &window)
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(px, py), sf::Color::Red),
		sf::Vertex(sf::Vector2f(px + p_deltax * 5, py + p_deltay * 5), sf::Color::Red)
	};
	std::cout << "p_angle: " << p_angel << std::endl;
	window.draw(line, 2, sf::Lines);
	window.draw(this->Player_Body);
}
