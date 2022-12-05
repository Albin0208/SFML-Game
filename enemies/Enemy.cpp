//
// Created by albin on 2022-12-05.
//

#include "Enemy.h"

Enemy::Enemy(sf::Vector2f const& position, float speed)
    : MovableObject(position, speed), health{100}, attack_speed{1.f}, attack_timer_max{500} {
    attack_timer.restart();
}