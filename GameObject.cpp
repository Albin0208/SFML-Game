//
// Created by albin on 2022-12-01.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(sf::Vector2f const& position)
        : position{position}, alive{true} {
    //hitbox.setSize(sf::Vector2f{50, 50});
//    hitbox.setTexture(*TextureManager::get("professor-walk-cycle-no-hat.png"));
//    hitbox.setTextureRect({0, 0, 61, 61});
    hitbox.setPosition(position);
    //hitbox.setScale(2.5f, 2.5f);
    //hitbox.setFillColor(sf::Color::Green);
}

bool GameObject::checkCollision(GameObject const& obj) {
    return this->hitbox.getGlobalBounds().intersects(obj.hitbox.getGlobalBounds());
}

bool GameObject::is_alive() const {
    return alive;
}
