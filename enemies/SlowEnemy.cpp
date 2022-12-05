//
// Created by albin on 2022-12-05.
//

#include "SlowEnemy.h"

SlowEnemy::SlowEnemy(sf::Vector2f const& position, float speed) : Enemy(position, speed) {
    shape.setFillColor(sf::Color::Red);
}

void SlowEnemy::update(sf::Time const& time, Game& game) {

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
