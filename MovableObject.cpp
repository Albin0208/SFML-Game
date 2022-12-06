//
// Created by albin on 2022-12-05.
//

#include "MovableObject.h"

MovableObject::MovableObject(sf::Vector2f const& position, float speed, Animation animation) : GameObject(position, animation), speed{speed} {}

void MovableObject::render(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(sprite);
}
