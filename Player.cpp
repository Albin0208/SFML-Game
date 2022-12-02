//
// Created by albin on 2022-12-01.
//

#include <cmath>
#include <iostream>
#include "Player.h"

Player::Player(sf::Vector2f const& position) : GameObject(position), speed{300.0f} {}

static sf::Vector2f find_direction() {
    sf::Vector2f direction{};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    // Normalize movement
    float len{static_cast<float>(sqrt(pow(direction.x, 2) + pow(direction.y, 2)))};
    if (len > 0.0f)
        return direction * (1.0f / len);
    else
        return direction;
}


void Player::update(sf::Time const& time, Game& game) {
    auto dir{find_direction()};
    position += dir * (speed * time.asMicroseconds() / 1000000.0f);
    shape.setPosition(position);

    // TODO: Check for moving out if window

    for (auto& o : game.collides_with(*this)) {
        // TODO: Do some stuff on collision depending on what type it is
    }

}

void Player::render(sf::RenderWindow& window) {
    window.draw(shape);
}
