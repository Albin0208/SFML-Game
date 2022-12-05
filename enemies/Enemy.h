//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_ENEMY_H
#define TDP005_ENEMY_H

#include "../MovableObject.h"

class Enemy : public MovableObject {
public:
    //TODO: Take health as a constructor parameter
    Enemy(sf::Vector2f const& position, float speed);
    virtual ~Enemy() = default;


    void update(sf::Time const& time, Game& game) override = 0;
    void render(sf::RenderWindow& window) override = 0;

private:
    int health;
};


#endif //TDP005_ENEMY_H
