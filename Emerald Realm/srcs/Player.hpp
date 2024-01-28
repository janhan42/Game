/**
 * @file Player.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include "SpriteUpdate.hpp"

#define delTime 0.5f;

class	Player
{
	public:
		enum type {
			PRESSED = 1,
			RELEASED = 0,
			MOUSELEFT = 3,
			MOUSERITG = 4
		};

		enum Action {
			idleDown,
			idle,
			idleUp,
			moveDown,
			move,
			moveUp,
			attackDown,
			attack,
			attackUp,
			Die
		};

		Player(int totalFrame);
		~Player();
		/* inPut */
		void	inPut(int keyCode, int type);
		/* get */
		sf::Vector2f	getPosition();
		float			getHealthPoint();
		float			getStamina();
		sf::Sprite		getSprite();
		/* set */
		void	setPosition(sf::Vector2f Accelation);
		void	setHealthPoint(float	newHealthPoint);
		void	setStamina(float	newStamina);
		void	setCur(int cur)
		{
			this->cur = cur;
		}
		/* UPDATE */
		void	setSprite();
		void	upDate();

	private:
	/*	임시 본체 */
	/* -------- */
		sf::Vector2f	_size;
		sf::IntRect		_rect;
		sf::Texture		_textuer;
		sf::Sprite		_sprite;
		float			_healthPoints;
		float			_stamina;
		float			frame;
		float			frameSpeed;
		sf::Vector2f	*movement;
		int				*frameMax;
		bool			*Action;
		bool			revers;
		bool			moving;
		bool			updown;

};