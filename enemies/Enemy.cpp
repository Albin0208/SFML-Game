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
