//
// Created by albin on 2022-12-01.
//

#include "GameObject.h"

GameObject::GameObject(sf::Vector2f const& position) : position{position}, alive{true}{
    shape.setSize(sf::Vector2f{50, 50});
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Green);
}

bool GameObject::checkCollision(GameObject const& obj) {
    return this->shape.getGlobalBounds().intersects(obj.shape.getGlobalBounds());
}

bool GameObject::is_alive() const {
    return alive;
}
