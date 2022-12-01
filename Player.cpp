//
// Created by albin on 2022-12-01.
//

#include <valarray>
#include <iostream>
#include "Player.h"

Player::Player(sf::Vector2f const& position) : GameObject(position), speed{300.0f} {}

static sf::Vector2f find_direction(sf::RenderWindow& window) {
    sf::Vector2f direction;
    if (window.hasFocus() && sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (window.hasFocus() && sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (window.hasFocus() && sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (window.hasFocus() && sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    float len = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    if (len > 0.0f)
        return direction * (1.0f / len);
    else
        return direction;
}


void Player::update(sf::Time const& time, sf::RenderWindow& window) {
    auto dir{find_direction(window)};
    position += dir * (speed * time.asMicroseconds() / 1000000.0f);
    shape.setPosition(position);
}

void Player::render(sf::RenderWindow& window) {
    window.draw(shape);
}
