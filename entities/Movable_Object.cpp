//
// Created by albin on 2022-12-05.
//

#include "Movable_Object.h"

Movable_Object::Movable_Object(sf::Vector2f const& position, float speed)
    : Game_Object(position), speed{speed}, face_right{true}, attacking{false} {
}

void Movable_Object::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Movable_Object::obstacle_collision(Obstacle* obstacle) {
    // Not able to pass through an obstacle
    sf::Vector2f obstacle_center = obstacle->get_pos() + (obstacle->get_size() / 2.f);
    sf::Vector2f moving_object_center = position + (hitbox.getSize() / 2.f);
    sf::Vector2f distance = moving_object_center - obstacle_center;

    if(std::abs(distance.x) >= std::abs(distance.y)) {// To the right or left of obstacle
        if (distance.x <= 0)
            position.x = obstacle->get_pos().x - hitbox.getSize().x; // To the left of the obstacle
        else
            position.x = obstacle->get_pos().x + obstacle->get_size().x; // To the right of the obstacle
    } else { // Above or below obstacle
        if (distance.y <= 0)
            position.y = obstacle->get_pos().y - hitbox.getSize().y; // Above teh obstacle
        else
            position.y = obstacle->get_pos().y + obstacle->get_size().y; //Below the obstacle
    }
}


void Movable_Object::take_damage(int damage) {
    // Make sure that we have taken damage
    if (damage > 0) {
        sprite.setColor(sf::Color::Red);
        dmg_clock.restart();
        health -= damage;
    }
}