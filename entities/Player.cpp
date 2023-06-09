//
// Created by albin on 2022-12-01.
//

#include <cmath>
#include <algorithm>
#include <iostream>
#include "Player.h"
#include "enemies/Slow_Enemy.h"
#include "Projectile.h"
#include "Obstacle.h"
#include "../utility/Texture_Manager.h"

Player::Player(sf::Vector2f const& position, float speed)
    : Movable_Object(position, speed, 135.f){
    set_animations();
    attack_timer_max = 500;
    health = 100;
    sprite.setScale(1.f, 1.f);

    animation_manager.play("idle", sprite);

    hitbox.setSize({sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 1.5f});
}

/**
 * Find the direction the player should be moving in
 * @return The direction
 */
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

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (attack_timer.getElapsedTime().asMilliseconds() > attack_timer_max) {
            attack_timer.restart();
            sf::Vector2f mouse_pos{sf::Mouse::getPosition(*game.get_window())};

            sf::Vector2f projectile_dir{mouse_pos - (position+(hitbox.getSize()*0.5f))};

            // Normalize the projectile-direction-vector
            projectile_dir /= static_cast<float>(sqrt(pow(projectile_dir.x, 2) + pow(projectile_dir.y, 2)));

            game.add(std::make_shared<Projectile>(
                    sf::Vector2f{position.x + (hitbox.getSize().x / 2), position.y + (hitbox.getSize().y / 2)},
                    300.f, projectile_dir, 40, Objects_to_hit::all_enemies));
            attacking = true;
        }
    }

    if (dir.x == 0 && dir.y == 0)
        animation_type = "idle";

    handle_animation(dir);

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

    for (auto& o : game.collides_with(*this)) {
        if (auto e = std::dynamic_pointer_cast<Obstacle>(o)) {
            // Not able to pass through an obstacle
            obstacle_collision(e.get());
        }
    }

    sprite.setPosition({hitbox.getPosition().x - hitbox.getSize().x / 2, hitbox.getPosition().y - hitbox.getSize().y / 4});

    if (health <= 0)
        game.is_game_over = true;

    if (dmg_clock.getElapsedTime().asMilliseconds() > 60)
        sprite.setColor(sf::Color::White);
}

sf::Vector2f const& Player::get_pos() const{
    return position;
}

int Player::attack() {
    return 0;
}

void Player::set_animations() {
    // Add walk animation
    animation_manager.add_animation("walk", Texture_Manager::get("player_angel2.png"),
                                    24, 2 / 60.f);
    animation_manager.add_animation("idle", Texture_Manager::get("idle.png"),
                                    18, 4 / 60.f);
    animation_manager.add_animation("attack", Texture_Manager::get("player_attack.png"),
                                    12, 2.5 / 60.f);
}

int Player::get_hp() const {
    return health;
}
