//
// Created by albin on 2022-12-12.
//

#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f const& position, sf::Texture* texture) : Game_Object(position) {
    shape.setRadius(50);
    hitbox.setSize({100, 100});
    shape.setFillColor(sf::Color::White);
    hitbox.setFillColor(sf::Color::Red);
//    shape.setPosition(position);
}

void Obstacle::update(sf::Time const& time, Game& game) {

}

void Obstacle::render(sf::RenderWindow& window) {
    window.draw(hitbox);
//    window.draw(shape);
}

sf::CircleShape const& Obstacle::get_shape() const {
    return shape;
}

sf::RectangleShape Obstacle::get_pos() const {
    return hitbox;
}
