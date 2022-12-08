//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_SLOWENEMY_H
#define TDP005_SLOWENEMY_H


#include "Enemy.h"

class SlowEnemy : public Enemy {
public:
    SlowEnemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos);

    void update(const sf::Time &time, Game &game) override;

    int attack(sf::Time const& time) override;

protected:
    void set_animations() override;

public:
    void take_damage(int damage) override;

private:
    bool attacking{false};
};


#endif //TDP005_SLOWENEMY_H
