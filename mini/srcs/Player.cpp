#include "Player.hpp"

Player::Player(float x, float y) : isUp(false), isDown(false), isLeft(false), isRight(false), velocityY(0.0f) ,gravity(9.8f){
    rect.setSize(sf::Vector2f(x, y));
}

void Player::processEvents(sf::Keyboard::Key key, bool checkPressed) {
    if (checkPressed) {
         if (key == sf::Keyboard::W && !isJumping) { // Allow jumping only if not already jumping
            jump();
        }
        if (key == sf::Keyboard::S)
            isDown = true;
        if (key == sf::Keyboard::A)
            isLeft = true;
        if (key == sf::Keyboard::D)
            isRight = true;
    } else {
        isUp = isDown = isLeft = isRight = false;
    }
}

void Player::jump() {
    isJumping = true;
    velocityY = -60.0f; // Adjust this value based on the desired jump height
}

void Player::update(float deltaTime) {
    applyGravity(deltaTime); // Apply gravity first
    sf::Vector2f movement = sf::Vector2f(0.0f, velocityY) * deltaTime;
    if (isUp)
        movement.y -= 5.0;
    if (isDown)
        movement.y += 5.0;
    if (isLeft)
        movement.x -= 5.0;
    if (isRight)
        movement.x += 5.0;

    rect.move(movement);
    limitToScreenBounds(); // Limit movement to screen bounds
	if (rect.getPosition().y + rect.getSize().y >= 800) {
        isJumping = false; // Allow jumping again when on the ground
        rect.setPosition(rect.getPosition().x, 800 - rect.getSize().y);
    }
}

void Player::applyGravity(float deltaTime) {
    velocityY += gravity * deltaTime;
}

void Player::limitToScreenBounds() {
    // Limit to the top of the screen
    if (rect.getPosition().y < 0)
        rect.setPosition(rect.getPosition().x, 0);

    // Limit to the bottom of the screen
    if (rect.getPosition().y + rect.getSize().y > 800)
        rect.setPosition(rect.getPosition().x, 800 - rect.getSize().y);

    // Limit to the left of the screen
    if (rect.getPosition().x < 0)
        rect.setPosition(0, rect.getPosition().y);

    // Limit to the right of the screen
    if (rect.getPosition().x + rect.getSize().x > 1280)
        rect.setPosition(1280 - rect.getSize().x, rect.getPosition().y);
}

void Player::drawTo(sf::RenderWindow &window) {
    window.draw(rect);
}
