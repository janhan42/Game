/**
 * @file core.cpp
 * @author jang hun han (janhan@student.42Seoul.kr)
 * @brief
 * @version 0.1
 * @date 2024-01-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "core.hpp"
#include "SFML/Window/VideoMode.hpp"

callender::callender()
: window(sf::VideoMode video(sf::Vector2f(1000, 1000)))
{

}
