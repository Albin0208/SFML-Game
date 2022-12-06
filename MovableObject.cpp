//
// Created by albin on 2022-12-05.
//

#include "MovableObject.h"

MovableObject::MovableObject(sf::Vector2f const& position, float speed) : GameObject(position), speed{speed} {}

void MovableObject::render(sf::RenderWindow& window) {
    window.draw(shape);
}
