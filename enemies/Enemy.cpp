//
// Created by albin on 2022-12-05.
//

#include "Enemy.h"

Enemy::Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos, int points)
    : Movable_Object(position, speed), health{100}, player_pos{player_pos}, points{points} {
    attack_timer.restart();
}

int Enemy::get_points() const {
    return points;
}

void Enemy::update(sf::Time const& time, Game& game) {
    if (health <= 0) {
        animation_manager.force_play("dying", sprite);
        type = "dying";
        if (animation_manager.is_done("dying")) {
            alive = false;
            animation_manager.kill();
            game.enemy_killed();
            game.add_points(points);
        }
    }
}
