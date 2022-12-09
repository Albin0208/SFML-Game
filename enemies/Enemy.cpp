//
// Created by albin on 2022-12-05.
//

#include "Enemy.h"

Enemy::Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos)
    : Movable_Object(position, speed), health{100}, attack_speed{1.f}, player_pos{player_pos} {
    attack_timer.restart();
}