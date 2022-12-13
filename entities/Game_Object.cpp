//
// Created by albin on 2022-12-01.
//

#include "Game_Object.h"
#include "../utility/Texture_Manager.h"
#include "Obstacle.h"

Game_Object::Game_Object(sf::Vector2f const& position)
        : position{position}, alive{true} {
    //hitbox.setSize(sf::Vector2f{50, 50});
//    hitbox.setTexture(*Texture_Manager::get("professor-walk-cycle-no-hat.png"));
//    hitbox.setTextureRect({0, 0, 61, 61});
    hitbox.setPosition(position);
    //hitbox.setScale(2.5f, 2.5f);
    //hitbox.setFillColor(sf::Color::Green);
}

bool Game_Object::checkCollision(Game_Object const& obj) {
    return this->hitbox.getGlobalBounds().intersects(obj.hitbox.getGlobalBounds());
}

bool Game_Object::is_alive() const {
    return alive;
}
