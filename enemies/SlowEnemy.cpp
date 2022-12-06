//
// Created by albin on 2022-12-05.
//

#include "SlowEnemy.h"

#include <utility>
#include <iostream>

SlowEnemy::SlowEnemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos) : Enemy(position, speed, player_pos) {
    shape.setFillColor(sf::Color::Red);
}

void SlowEnemy::update(sf::Time const& time, Game& game,sf::RenderWindow const& window) {
    sf::Vector2f dir{player_pos - shape.getPosition()};

    dir /= static_cast<float>(sqrt(pow(dir.x, 2) + pow(dir.y, 2)));

    position += speed * dir * time.asSeconds();
    shape.setPosition(position);



    for (auto& o : game.collides_with(*this)) {
        // TODO: Take damage from player projectiles

        if (health <= 0)
            alive = false;
//        position = shape.getPosition() - dir * speed * time.asSeconds();
//        shape.setPosition(position);
    }
}

int SlowEnemy::attack() {
    if (attack_timer.getElapsedTime().asMilliseconds() > attack_timer_max) {
        attack_timer.restart();
        return 5;
    }

    return 0;
}
