//
// Created by albin on 2022-12-05.
//

#include "Enemy.h"

#include <utility>

Enemy::Enemy(sf::Vector2f const& position, float speed, sf::RectangleShape const& player_pos)
    : MovableObject(position, speed), health{100}, attack_speed{1.f}, attack_timer_max{500}, player_pos{player_pos} {
    attack_timer.restart();
}