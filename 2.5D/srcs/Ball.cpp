/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ball.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 01:03:44 by janhan            #+#    #+#             */
/*   Updated: 2023/12/24 19:06:48 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ball.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include <vector>
#include <cmath>

Ball::Ball(float pos_x, float pos_y)
    : pos(pos_x, pos_y)
{
    ball.setRadius(20.0f); // 반지름 설정
    ball.setFillColor(sf::Color::White);
    ball.setPosition(pos);
    ball.setOrigin(ball.getRadius(), ball.getRadius());
    ball.setFillColor(sf::Color::White);
    mass = (1.0f);
    dt = (0.01f);
}

void            Ball::draw(sf::RenderWindow &window)
{ window.draw(ball); }
void            Ball::setVelocity(sf::Vector2f vel)
{ this->vel = vel; }
void            Ball::setPosition(sf::Vector2f pos)
{ this->pos = pos; }
void            Ball::setStartPoint(sf::RenderWindow& window)
{ startPoint = ball.getOrigin(); }
void            Ball::setEndPoint(sf::RenderWindow& window)
{ endPoint = ball.getOrigin(); }
sf::Vector2f    Ball::getPosition()
{ return ball.getPosition(); }
float           Ball::getRadius()
{ return ball.getRadius(); }
sf::Vector2f    Ball::getVelocity()
{ return this->vel; }
float           Ball::getMass()
{ return this->mass; }
float           Ball::dotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2)
{ return v1.x * v2.x + v1.y * v2.y; }
void            Ball::updatePhysics(std::vector<Ball>& vecBall, sf::RenderWindow& window)
{
    sf::Vector2f newPosition = pos + vel * dt;

    // 충돌 처리
    for (auto& otherBall : vecBall)
    {
        if (&otherBall != this)
        {
            sf::Vector2f distVector = otherBall.getPosition() - newPosition;
            float distance = std::sqrt(distVector.x * distVector.x + distVector.y * distVector.y);
            const float midDistance = getRadius() + otherBall.getRadius();
            if (distance < midDistance)
            {
                sf::Vector2f nomal = distVector / distance;
                sf::Vector2f relativeVelocity = otherBall.getVelocity() - vel;
                float inpulse = (2.0f * mass * otherBall.getMass() /
                                 (mass + otherBall.getMass()) * dotProduct(relativeVelocity, nomal));
                vel += (inpulse / mass) * nomal;
                otherBall.setVelocity(otherBall.getVelocity() - (inpulse / otherBall.getMass()) * nomal);
                float overlap = midDistance - distance;
                sf::Vector2f correction = (overlap / 2.0f) * (distVector / distance);
                newPosition -= correction;
                otherBall.setPosition(otherBall.getPosition() + correction);
            }
        }
    }

    // 화면 경계 처리
    if (newPosition.x < 0) newPosition.x += window.getSize().x;
    if (newPosition.x >= window.getSize().x) newPosition.x -= window.getSize().x;
    if (newPosition.y < 0) newPosition.y += window.getSize().y;
    if (newPosition.y >= window.getSize().y) newPosition.y -= window.getSize().y;

    pos = newPosition;
    ball.setPosition(pos);
}
