//
// Created by albin on 2022-12-01.
//

#include "Game.h"
#include "Player.h"

Game::Game() {}

void Game::update(sf::Time const& time) {
    for (auto const& o : objects) {
        o->update(time, *this);
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

    for (auto& o : objects) {
        // Check for self collision
        if (o.get() == &obj)
            continue;
        // Check obj collides with any object
        if (obj.checkCollision(*o))
            collided_with.push_back(o);
    }

    return collided_with;
}
