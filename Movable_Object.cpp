//
// Created by albin on 2022-12-05.
//

#include "Movable_Object.h"

Movable_Object::Movable_Object(sf::Vector2f const& position, float speed)
    : Game_Object(position), speed{speed}, face_right{true} {
}

void Movable_Object::render(sf::RenderWindow& window) {
//    hitbox.setFillColor(sf::Color::White);
//    window.draw(hitbox);
    window.draw(sprite);
}
