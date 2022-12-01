//
// Created by albin on 2022-12-01.
//

#include "GameState.h"
#include "MenuState.h"
#include "Player.h"

GameState::GameState() {
    // Create the player and add to game
    game.add(std::make_shared<Player>(sf::Vector2f{50, 50}));
}

std::shared_ptr<State> GameState::update(const sf::Time& time, sf::RenderWindow& window) {
    game.update(time, window);

    // We pause the game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !window.hasFocus())
        return std::make_shared<MenuState>(shared_from_this());

    return nullptr;
}

void GameState::render(sf::RenderWindow& target) {
    game.render(target);
}