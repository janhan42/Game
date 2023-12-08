#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(float x, float y);

    void processEvents(sf::Keyboard::Key key, bool checkPressed);
    void update(float deltaTime); // Added deltaTime for smooth movement
    void applyGravity(float deltaTime); // Added gravity function
    void limitToScreenBounds(); // Added screen boundary limiting function
    void drawTo(sf::RenderWindow &window);
	void jump();
private:
    sf::RectangleShape rect;
    bool isUp;
    bool isDown;
    bool isLeft;
    bool isRight;
    float velocityY; // Added vertical velocity for gravity
	bool isJumping;
    const float gravity ; // Added gravity strength
};
