//
// Created by albin on 2022-12-01.
//

#include <cmath>
#include <iostream>
#include "Player.h"
#include "enemies/SlowEnemy.h"
#include "TextureManager.h"

Player::Player(sf::Vector2f const& position, float speed)
    : MovableObject(position, speed) {
    set_animations();
    hitbox.setSize({100, 135});
    //sprite.setTexture(*TextureManager::get("run_player.png"));
    sprite.setScale({0.15f, 0.15f});

    animation_manager.play("idle", sprite);

    //animations.find("idle")->second.update(0, 0, false, sprite);
    //sprite.setTextureRect(animations.find("walk")->second.uv_rect);
    hitbox.setSize({sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 1.5f});
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

    if (dir.x == 0 && dir.y == 0)
        type = "idle";
    if (dir.x > 0 || dir.y != 0 && face_right) {
        sprite.setOrigin(0.f, 0.f);
        sprite.setScale(0.15f, 0.15f);
        face_right = true;
        type = "walk";
    }
    if (dir.x < 0 || dir.y != 0 && !face_right) {
        sprite.setOrigin(900.f, 0.f);
        sprite.setScale(-0.15f, 0.15f);
        face_right = false;
        type = "walk";
    }

    animation_manager.play(type, sprite);
//    animations.find(type)->second.update(0, time.asSeconds(), false, sprite);

    // Check for moving out if window
    // Left collision
    if (position.x < 0.f)
        position = {0.f, position.y};
    // Top collision
    if (position.y < 0.f)
        position = {position.x, 0.f};
    // Right collision
    if (position.x + hitbox.getGlobalBounds().width > WIDTH)
        position = {WIDTH - hitbox.getGlobalBounds().width, position.y};
    // Bottom collision
    if (position.y + hitbox.getGlobalBounds().height > HEIGHT)
        position = {position.x, HEIGHT- hitbox.getGlobalBounds().height};

    hitbox.setPosition(position);
    sprite.setPosition({hitbox.getPosition().x - hitbox.getSize().x / 2, hitbox.getPosition().y - hitbox.getSize().y / 4});

    for (auto& o : game.collides_with(*this)) {
        // TODO: Do some stuff on collision depending on what type it is
        if (auto e = dynamic_cast<Enemy*>(o.get())) {
            health -= e->attack(time);
            // We have 0 health, the game is over
            if (health <= 0)
                game.is_game_over = true;

            // Not able to pass through an enemy
//            position = hitbox.getPosition() - dir * speed * time.asSeconds();
//            hitbox.setPosition(position);
        }
    }
}

sf::Vector2f const& Player::get_pos() {
    return position;
}

int Player::attack(sf::Time const& time) {
    return 0;
}

void Player::set_animations() {
    // Add walk animation
    animation_manager.add_animation("walk", TextureManager::get("player_angel2.png"),
                                    sf::Vector2u{24, 1}, 2 / 60.f);
    animation_manager.add_animation("idle", TextureManager::get("idle.png"),
                                    sf::Vector2u{18, 1}, 4 / 60.f);
}
