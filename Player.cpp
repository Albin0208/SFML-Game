//
// Created by albin on 2022-12-01.
//

#include <cmath>
#include <iostream>
#include "Player.h"
#include "enemies/SlowEnemy.h"

Player::Player(sf::Vector2f const& position, float speed) : MovableObject(position, speed), health{100} {}

static sf::Vector2f find_direction() {
    sf::Vector2f direction{0, 0};
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
    shape.move(dir * speed * time.asSeconds());

    // Check for moving out if window
    // Left collision
    if (shape.getPosition().x < 0.f)
        shape.setPosition(0.f, shape.getPosition().y);
    // Top collision
    if (shape.getPosition().y < 0.f)
        shape.setPosition(shape.getPosition().x, 0.f);
    // Right collision
    if (shape.getPosition().x + shape.getGlobalBounds().width > WIDTH)
        shape.setPosition(WIDTH - shape.getGlobalBounds().width, shape.getPosition().y);
    // Bottom collision
    if (shape.getPosition().y + shape.getGlobalBounds().height > HEIGHT)
        shape.setPosition(shape.getPosition().x, HEIGHT- shape.getGlobalBounds().height);

    for (auto& o : game.collides_with(*this)) {
        // TODO: Do some stuff on collision depending on what type it is
        if (auto e = dynamic_cast<Enemy*>(o.get())) {
            health -= e->attack();
            std::cout << health << std::endl;

            // Not able to pass through an enemy
            position = shape.getPosition() - dir * speed * time.asSeconds();
            shape.setPosition(position);
        }
    }

}

void Player::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::RectangleShape const& Player::get_pos() {
    return shape;
}
