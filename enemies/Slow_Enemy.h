//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_SLOW_ENEMY_H
#define TDP005_SLOW_ENEMY_H


#include "Enemy.h"

class Slow_Enemy : public Enemy {
public:
    Slow_Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos);

    void update(const sf::Time &time, Game &game) override;

    int attack() override;

protected:
    void set_animations() override;

public:
    void take_damage(int damage) override;

private:
    bool attacking{false};
};


#endif //TDP005_SLOW_ENEMY_H
