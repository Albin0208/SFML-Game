//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_PLAYER_H
#define TDP005_PLAYER_H

#include "Movable_Object.h"

class Player : public Movable_Object {
public:
    Player(sf::Vector2f const& position, float speed);

    void update(sf::Time const& time, Game& game) override;

    int attack() override;

    sf::Vector2f const& get_pos();

    void take_damage(int damage);

protected:
    void set_animations() override;

private:
    int health;
    sf::Clock attack_timer;
    bool attacking;
};


#endif //TDP005_PLAYER_H
