//
// Created by albin on 2022-12-05.
//

#include "MovableObject.h"

MovableObject::MovableObject(sf::Vector2f const& position, float speed)
    : GameObject(position), speed{speed}, face_right{true} {
}

void MovableObject::render(sf::RenderWindow& window) {
    hitbox.setFillColor(sf::Color::White);
    window.draw(hitbox);
    window.draw(sprite);
}
