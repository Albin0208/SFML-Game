//
// Created by ingva on 2022-12-09.
//

#ifndef TDP005_RANGED_ENEMY_H
#define TDP005_RANGED_ENEMY_H

#include "SFML/System/Vector2.hpp"
#include "../../Game.h"
#include "Enemy.h"

class Ranged_Enemy : public Enemy {
public:
    Ranged_Enemy(sf::Vector2f const& position1, float speed1, sf::Vector2f const& playerPos);

    void update(const sf::Time &time, Game &game) override;

    int attack() override;

protected:
    void set_animations() override;

private:
    float range;
};

#endif //TDP005_RANGED_ENEMY_H
