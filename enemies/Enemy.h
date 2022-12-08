//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_ENEMY_H
#define TDP005_ENEMY_H

#include "../MovableObject.h"

class Enemy : public MovableObject {
public:
    //TODO: Take health as a constructor parameter
    Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos);
    ~Enemy() override = default;


    void update(sf::Time const& time, Game& game) override = 0;

    int attack(sf::Time const& time) override = 0;

protected:
    void set_animations() override = 0;

    sf::Vector2f const& player_pos;
    int health;
    float attack_speed;
};


#endif //TDP005_ENEMY_H
