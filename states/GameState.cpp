//
// Created by albin on 2022-12-01.
//

#include "GameState.h"
#include "MenuState.h"
#include "../Player.h"
#include "../enemies/SlowEnemy.h"

GameState::GameState() {
    // Create the player and add to game
    game.add(std::make_shared<Player>(sf::Vector2f{50, 50}, 300.f));
    game.add(std::make_shared<SlowEnemy>(sf::Vector2f{200, 400}, 300.f));
}

std::shared_ptr<State> GameState::update(sf::Time const& time, sf::RenderWindow const& window) {
    game.update(time);

    // We pause the game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !window.hasFocus())
        return std::make_shared<MenuState>(shared_from_this());

    return nullptr;
}

void GameState::render(sf::RenderWindow& target) {
    game.render(target);
}