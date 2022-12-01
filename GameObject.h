//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAMEOBJECT_H
#define TDP005_GAMEOBJECT_H


#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class GameObject {
public:
    GameObject(sf::Vector2f const& position);
    virtual ~GameObject() = default;

    virtual void update(sf::Time const& time, sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

protected:
    sf::RectangleShape shape;
    sf::Vector2f position;
};


#endif //TDP005_GAMEOBJECT_H
