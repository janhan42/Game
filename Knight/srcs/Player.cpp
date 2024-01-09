/**
 * @file Player.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-08
 *
 * @copyright Copyright (c) 2024
 *
 */

 #include "Player.hpp"
#include "SFML/Graphics/Texture.hpp"

Player::Player()
{
	sf::Texture Idle;
	sf::Texture Left;
	sf::Texture Right;
	sf::Texture Jump;
	sf::Texture Attack;
	sf::Texture Slide;
	sf::Texture Crouch;
	sf::Texture Roll;
	sf::Texture Death;
	if (!Idle.loadFromFile("srcs/texture/_Idle.png"))
		exit(1);
	if (!Left.loadFromFile("srcs/texture/_Run.png"))
		exit(1);
	if (!Right.loadFromFile("srcs/texture/_Run.png"))
		exit(1);
	if (!Jump.loadFromFile("srcs/texture/_Jump2.png"))
		exit(1);
	if (!Attack.loadFromFile("srcs/texture/_AttackCombo.png"))
		exit(1);
	if (!Slide.loadFromFile("srcs/texture/_Slide.png"))
		exit(1);
	if (!Crouch.loadFromFile("srcs/texture/_CrouchAll.png"))
		exit(1);
	if (!Roll.loadFromFile("srcs/texture/_Roll.png"))
		exit(1);
	if (!Death.loadFromFile("srcs/texture/_Death.png"))
		exit(1);

	textures.push_back(Idle);
	textures.push_back(Left);
	textures.push_back(Right);
	textures.push_back(Jump);
	textures.push_back(Attack);
	textures.push_back(Slide);
	textures.push_back(Crouch);
	textures.push_back(Roll);
	textures.push_back(Death);
}

sf::Texture& Player::getTexture(int PlayerState)
{
	return textures[PlayerState];
}
