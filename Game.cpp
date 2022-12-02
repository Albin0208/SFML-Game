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
