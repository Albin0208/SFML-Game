//
// Created by albin on 2022-12-01.
//

#include "GameState.h"
#include "MenuState.h"

GameState::GameState() {

}

std::shared_ptr<State> GameState::update(const sf::Time& time) {
    game.update(time);

    // We pause the game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return std::make_shared<MenuState>(shared_from_this());

    return nullptr;
}

void GameState::render(sf::RenderWindow& target) {
    game.render(target);
}