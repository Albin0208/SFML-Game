//
// Created by albin on 2022-12-05.
//

#include "Enemy.h"

Enemy::Enemy(sf::Vector2f const& position, float speed) : MovableObject(position, speed), health{100} {}

void Enemy::update(sf::Time const& time, Game& game) {

}

void Enemy::render(sf::RenderWindow& window) {

}
