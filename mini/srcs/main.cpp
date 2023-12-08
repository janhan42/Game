#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <SFML/Window.hpp>
#include "SFML/Graphics.hpp"
#include "Player.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "Space Game");
    window.setFramerateLimit(60);
    sf::Event event;

    Player User(50.f, 50.f);

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                User.processEvents(event.key.code, true);
            if(event.type == sf::Event::KeyReleased)
                User.processEvents(event.key.code, false);
        }
        window.clear();
        User.drawTo(window);
        User.update(0.5f);
        window.display();
    }

}
