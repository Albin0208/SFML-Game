//
// Created by albin on 2022-12-01.
//

#include "Game_Object.h"
#include "../utility/Texture_Manager.h"
#include "Obstacle.h"

Game_Object::Game_Object(sf::Vector2f const& position)
        : position{position}, alive{true} {
    hitbox.setPosition(position);
}

bool Game_Object::checkCollision(Game_Object const& obj) {
    return this->hitbox.getGlobalBounds().intersects(obj.hitbox.getGlobalBounds());
}

bool Game_Object::is_alive() const {
    return alive;
}
