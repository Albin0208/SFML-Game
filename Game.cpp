//
// Created by albin on 2022-12-01.
//

//#include <iostream>
#include <iostream>
#include "Game.h"
#include "Player.h"

Game::Game() : window{nullptr} {}

void Game::update(sf::Time const& time) {
    if (wave.is_over()) {
        vector<shared_ptr<Game_Object>>& tmp{wave.create(get_player_pos())};

        objects.reserve(tmp.size());
        // Move all the enemies to the object vector
        std::move(tmp.begin(), tmp.end(), std::back_inserter(objects));
    }

    for (size_t i{}; i < objects.size(); ++i) {
        if (objects[i] != nullptr) {
            objects[i]->update(time, *this);

            // If object is dead remove it
            if (!objects[i]->is_alive()) {
                objects.erase(objects.begin() + i);
                --i;
            }
        }
    }
}

void Game::render(sf::RenderWindow& target) {
    for (auto const& o : objects) {
        if (o != nullptr)
            o->render(target);
    }
}

void Game::add(std::shared_ptr<Game_Object> const& object) {
    objects.push_back(object);
}

std::vector<std::shared_ptr<Game_Object>> Game::collides_with(Game_Object& obj) {
    std::vector<std::shared_ptr<Game_Object>> collided_with{};

    for (auto const& o : objects) {
        // Check for self collision
        if (o == nullptr || o.get() == &obj)
            continue;

        // Check obj collides with any object
        if (obj.checkCollision(*o))
            collided_with.push_back(o);
    }

    return collided_with;
}

sf::Vector2f const& Game::get_player_pos() {
    return dynamic_cast<Player*>(objects.at(0).get())->get_pos();
}

void Game::enemy_killed() {
    wave.enemy_killed();
}
