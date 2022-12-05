//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_SLOWENEMY_H
#define TDP005_SLOWENEMY_H


#include "Enemy.h"

class SlowEnemy : public Enemy {
public:
    SlowEnemy(sf::Vector2f const& position, float speed);

    void update(const sf::Time &time, Game &game) override;
    void render(sf::RenderWindow &window) override;

    int attack() override;
private:
};


#endif //TDP005_SLOWENEMY_H
