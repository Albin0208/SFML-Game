//
// Created by albin on 2022-12-12.
//

#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f const& position, sf::Texture* texture, int texture_num) : Game_Object(position) {
    hitbox.setFillColor(sf::Color::White);
    sprite.setTexture(*texture);
    sprite.setPosition(position);
    sprite.setScale(3, 3);
    sprite.setTextureRect({17 * texture_num, 0, 17, 21});
    sprite.move(-5, -5);

    hitbox.setSize({sprite.getGlobalBounds().width / 1.3f, sprite.getGlobalBounds().height / 1.3f});
}

void Obstacle::update(sf::Time const& time, Game& game) {

}

void Obstacle::render(sf::RenderWindow& window) {
    window.draw(hitbox);
    window.draw(sprite);
}