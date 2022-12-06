//
// Created by albin on 2022-12-01.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(sf::Vector2f const& position, Animation animation)
        : position{position}, alive{true}, animation{animation} {
    //shape.setSize(sf::Vector2f{50, 50});
//    shape.setTexture(*TextureManager::get("professor-walk-cycle-no-hat.png"));
//    shape.setTextureRect({0, 0, 61, 61});
    shape.setPosition(position);
    //shape.setScale(2.5f, 2.5f);
    //shape.setFillColor(sf::Color::Green);
}

bool GameObject::checkCollision(GameObject const& obj) {
    return this->shape.getGlobalBounds().intersects(obj.shape.getGlobalBounds());
}

bool GameObject::is_alive() const {
    return alive;
}
