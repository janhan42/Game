/**
 * @file Player.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

class Player
{
	public:
		enum PlayerState
		{
			Idle,
			Left,
			Right,
			Jump,
			Attack,
			Slide,
			Crouch,
			Roll,
			Death,
		};


		Player();
		void				inPutHandle(sf::Sprite& playerSprite);
		sf::Texture&		getTexture(int PlayerState);

	private:
		std::vector<sf::Texture> textures;
		sf::Vector2f	position;
		sf::Vector2f	velocity;
		sf::Vector2f	gravity;

};
