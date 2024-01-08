/**
 * @brief
 *
 */
#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <ostream>
#include "Player.hpp"



typedef struct PlayerStatus{
	bool Idle;
	bool Left;
	bool Right;
	bool Jump;
	bool Attack;
	bool Slide;
	bool Crouch;
	bool Roll;
	bool Death;
} KeyInfo;
