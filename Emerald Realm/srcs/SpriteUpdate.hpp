/**
 * @file SpriteUpdate.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "SFML/Graphics/Sprite.hpp"
#pragma onec
#include <SFML/Graphics.hpp>

class	SpriteUpdate : public sf::Sprite
{
	public:
		SpriteUpdate();
		/*
		 * SetSprite는 MoveableObject들의 상태를 기반으로
		 * 몇변째 Sprite를 보여줘야하고 어떤 상태의 스프라이트를
		 * 보여줘야 하는지 세팅해주는 함수
		 * 필요 State
		 * 현재 보여줘야하는 상태의 enum * IMG_SIZE
		 * 현재 보여줘야하는 상태의 프레임 frameCount * IMG_SIZE;
		*/
		virtual	void	SetSprite(float	deltaTime) = 0;
	protected:
		sf::IntRect	_textureRect;
};