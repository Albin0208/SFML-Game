//
// Created by albin on 2022-12-05.
//

#include "SlowEnemy.h"

#include <utility>
#include <iostream>

SlowEnemy::SlowEnemy(sf::Vector2f const& position, float speed, sf::RectangleShape const& player_pos) : Enemy(position, speed, player_pos) {
    shape.setFillColor(sf::Color::Red);
}

void SlowEnemy::update(sf::Time const& time, Game& game) {
    sf::Vector2f dir{player_pos.getPosition() - shape.getPosition()};

    if (dir.x > 1)
        dir.x = 1;
    if (dir.x < -1)
        dir.x = -1;

    if (dir.y > 1)
        dir.y = 1;
    if (dir.y < -1)
        dir.y = -1;

    // Normalize movement
    float len{static_cast<float>(sqrt(pow(dir.x, 2) + pow(dir.y, 2)))};
    if (len > 0.0f)
        dir * (1.0f / len);
    shape.move(speed * dir * time.asSeconds());
}

void SlowEnemy::render(sf::RenderWindow& window) {
    window.draw(shape);
}

int SlowEnemy::attack() {
    if (attack_timer.getElapsedTime().asMilliseconds() > attack_timer_max) {
        attack_timer.restart();
        return 5;
    }

    return 0;
}
