//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_ENEMY_H
#define TDP005_ENEMY_H

#include "../MovableObject.h"

class Enemy : public MovableObject {
public:
    Enemy(sf::Vector2f const& position, float speed);


    void update(sf::Time const& time, Game& game) override;
    void render(sf::RenderWindow& window) override;

private:
};


#endif //TDP005_ENEMY_H
