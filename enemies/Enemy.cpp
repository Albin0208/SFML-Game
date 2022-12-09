//
// Created by albin on 2022-12-05.
//

#include "Enemy.h"

Enemy::Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos,
             int points, int health, int damage)
    : Movable_Object(position, speed), player_pos{player_pos}, points{points}, damage{damage} {
    attack_timer.restart();
    this->health = health;
}

void Enemy::update(sf::Time const& time, Game& game) {
    if (health <= 0) {
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