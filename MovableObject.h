//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_MOVABLEOBJECT_H
#define TDP005_MOVABLEOBJECT_H


#include "GameObject.h"

class MovableObject : public GameObject {
public:
    MovableObject(const sf::Vector2f &position, float speed);
    ~MovableObject() override = default;

    void update(const sf::Time &time, Game &game, sf::RenderWindow const& window) override = 0;
    void render(sf::RenderWindow &window) override = 0;
    virtual int attack() = 0;
protected:
    float speed;
};


#endif //TDP005_MOVABLEOBJECT_H
