//
// Created by albin on 2022-12-05.
//

#include "Movable_Object.h"

Movable_Object::Movable_Object(sf::Vector2f const& position, float speed)
    : Game_Object(position), speed{speed}, face_right{true}, attacking{false} {
}

void Movable_Object::render(sf::RenderWindow& window) {
//    hitbox.setFillColor(sf::Color::White);
//    window.draw(hitbox);
    window.draw(sprite);
}

void Movable_Object::take_damage(int damage) {
    // Make sure that we have taken damage
    if (damage > 0) {
        sprite.setColor(sf::Color::Red);
        dmg_clock.restart();
        health -= damage;
    }
}
