//
// Created by albin on 2022-12-01.
//

//#include <iostream>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "enemies/Enemy.h"

Game::Game() : window{nullptr} {}

Game::~Game() {
    delete window;
}


void Game::update(sf::Time const& time) {
    if (wave.is_over()) {
        wave.create(get_player_pos());
        vector<shared_ptr<GameObject>>& tmp{wave.get_enemies()};
        std::move(tmp.begin(), tmp.end(), std::back_inserter(objects));
    }

//    for (auto& o : objects)
//        o->update(time, *this);
//
//    // Delete dead objects
//    for (size_t i{}; i < objects.size(); ++i) {
//
//    }
//    std::cout << objects.size() << "\n";
    for (size_t i{}; i < objects.size(); ++i) {
        if (objects[i] != nullptr) {
            objects[i]->update(time, *this);
////        if (objects[i] != nullptr) {
//            if (objects[i]->update(time, *this)) {
//                objects.erase(objects.begin() + i);
//                --i;
//            }

            // If object is dead remove it
            if (!objects[i]->is_alive()) {
                objects.erase(objects.begin() + i);
                --i;
//                if (dynamic_cast<Enemy*>(objects[i].get())) {
//                    std::cout << "Enemy killed" << "\n";
//                    wave.enemy_killed();
//                }

            }
        }
//        } else {
////            objects.erase(objects.begin() + i);
////            --i;
//        }
    }

}

void Game::render(sf::RenderWindow& target) {
    for (auto const& o : objects) {
        if (o != nullptr)
            o->render(target);
    }
}

void Game::add(std::shared_ptr<GameObject> const& object) {
    objects.push_back(object);
}

std::vector<std::shared_ptr<GameObject>> Game::collides_with(GameObject& obj) {
    std::vector<std::shared_ptr<GameObject>> collided_with{};

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
    Player* o{dynamic_cast<Player*>(objects.at(0).get())};
    return o->get_pos();
}

void Game::enemy_killed() {
    wave.enemy_killed();
}
