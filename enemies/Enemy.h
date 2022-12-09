//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_ENEMY_H
#define TDP005_ENEMY_H

#include "../Movable_Object.h"

class Enemy : public Movable_Object {
public:
    //TODO: Take health as a constructor parameter
    Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos, int points);
    ~Enemy() override = default;


    void update(sf::Time const& time, Game& game) override = 0;

    int attack() override = 0;

    virtual void take_damage(int damage) = 0;

    int get_points() const;

protected:
    void set_animations() override = 0;

    sf::Vector2f const& player_pos;
    int health;
    int points;
};


#endif //TDP005_ENEMY_H
