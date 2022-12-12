//
// Created by albin on 2022-12-12.
//

#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f const& position, sf::Texture* texture) : Game_Object(position) {
    hitbox.setSize({50, 50});
    hitbox.setFillColor(sf::Color::White);
}

void Obstacle::update(sf::Time const& time, Game& game) {

}

void Obstacle::render(sf::RenderWindow& window) {
    window.draw(hitbox);
}