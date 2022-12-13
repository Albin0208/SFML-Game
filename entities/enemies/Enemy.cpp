//
// Created by albin on 2022-12-05.
//

#include "Enemy.h"

Enemy::Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos,
             int points, int health, int damage)
    : Movable_Object(position, speed), player_pos{player_pos}, points{points}, damage{damage}, max_health{health} {
    attack_timer.restart();
    this->health = health;
    health_bar_background.setSize({50, 5});
    health_bar_background.setFillColor(sf::Color::Red);
    health_bar_background.setOutlineThickness(1.f);
    health_bar_background.setOutlineColor(sf::Color::White);

    health_bar = health_bar_background;
    health_bar.setFillColor(sf::Color::Green);
}

void Enemy::update(sf::Time const& time, Game& game) {
    health_bar_background.setPosition(position);
    health_bar.setPosition(position);
    health_bar.setScale({static_cast<float>(health) / max_health, 1.f});

    if (health <= 0) {
        health_bar.setScale({0, 1});
        type = "dying";
        animation_manager.force_play(type, sprite);
        if (animation_manager.is_done("dying")) {
            alive = false;
            animation_manager.kill();
            game.enemy_killed();
            game.add_points(points);
        }
    }

    if (dmg_clock.getElapsedTime().asMilliseconds() > 60)
        sprite.setColor(sf::Color::White);
}

void Enemy::render(sf::RenderWindow& window) {
    Movable_Object::render(window);

    // Draw health bar
    window.draw(health_bar_background);
    window.draw(health_bar);
}
