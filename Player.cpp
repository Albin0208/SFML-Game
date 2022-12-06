//
// Created by albin on 2022-12-01.
//

#include <cmath>
#include <iostream>
#include "Player.h"
#include "enemies/SlowEnemy.h"
#include "TextureManager.h"

Player::Player(sf::Vector2f const& position, float speed) : MovableObject(position, speed,
                                              Animation{TextureManager::get("professor_walk_cycle_no_hat.png"),
                                                                                                     sf::Vector2u{9, 4}, 0.1f}), health{100} {
    shape.setSize({100, 100});
    sf::Texture* t{TextureManager::get("professor_walk_cycle_no_hat.png")};
    shape.setTexture(t);
    shape.setTextureRect(animation.uv_rect);
}

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

    if (direction != sf::Vector2f{0, 0})
        direction /= static_cast<float>(sqrt(pow(direction.x, 2) + pow(direction.y, 2)));

    return direction;
}

void Player::update(sf::Time const& time, Game& game) {
    auto dir{find_direction()};
    position += dir * speed * time.asSeconds();

    animation.update(3, time.asSeconds(), (dir.x > 0));
    if (dir.y < 0 && dir.x == 0)
        animation.update(0, time.asSeconds(), (dir.x > 0));
    else if (dir.y > 0 && dir.x == 0)
        animation.update(2, time.asSeconds(), (dir.x > 0));

    shape.setTextureRect(animation.uv_rect);

    // Check for moving out if window
    // Left collision
    if (position.x < 0.f)
        position = {0.f, position.y};
    // Top collision
    if (position.y < 0.f)
        position = {position.x, 0.f};
    // Right collision
    if (position.x + shape.getGlobalBounds().width > WIDTH)
        position = {WIDTH - shape.getGlobalBounds().width, position.y};
    // Bottom collision
    if (position.y + shape.getGlobalBounds().height > HEIGHT)
        position = {position.x, HEIGHT- shape.getGlobalBounds().height};

    shape.setPosition(position);

    for (auto& o : game.collides_with(*this)) {
        // TODO: Do some stuff on collision depending on what type it is
        if (auto e = dynamic_cast<Enemy*>(o.get())) {
            std::cout << "Hit" << std::endl;
            health -= e->attack();
            // We have 0 health, the game is over
            if (health <= 0)
                game.is_game_over = true;

            // Not able to pass through an enemy
//            position = shape.getPosition() - dir * speed * time.asSeconds();
//            shape.setPosition(position);
        }
    }
}

sf::Vector2f const& Player::get_pos() {
    return position;
}

int Player::attack() {
    return 0;
}
