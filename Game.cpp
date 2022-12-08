//
// Created by albin on 2022-12-01.
//

#include <iostream>
#include "Game.h"
#include "Player.h"

void Game::update(sf::Time const& time) {
    if (wave.is_over()) {
        wave.create(get_player_pos());
        vector<shared_ptr<GameObject>>& tmp{wave.get_enemies()};
        std::move(tmp.begin(), tmp.end(), std::back_inserter(objects));
    }

    for (size_t i{}; i < objects.size(); ++i) {
        objects[i]->update(time, *this);
        // If object is dead remove it
        if (!objects[i]->is_alive()) {
            objects.erase(objects.begin() + i);
            --i;
            wave.enemy_killed();
        }
    }
}

void Game::render(sf::RenderWindow& target) {
    for (auto const& o : objects) {
        o->render(target);
    }
}

void Game::add(std::shared_ptr<GameObject> const& object) {
    objects.push_back(object);
}

std::vector<std::shared_ptr<GameObject>> Game::collides_with(GameObject& obj) {
    std::vector<std::shared_ptr<GameObject>> collided_with{};

    std::cout << objects.size() << std::endl;

    for (auto& o : objects) {
        // Check for self collision
        if (o.get() == &obj || !o->is_alive())
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

Game::Game() {

}
