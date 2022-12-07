//
// Created by albin on 2022-12-01.
//

#include "GameState.h"
#include "MenuState.h"
#include "../Player.h"
#include "../enemies/SlowEnemy.h"
#include "GameOverState.h"

GameState::GameState() {
    // Create the player and add to game
    shared_ptr<Player> player{std::make_shared<Player>(sf::Vector2f{50, 50}, 300.f)};
    game.add(player);
    game.add(std::make_shared<SlowEnemy>(sf::Vector2f{200, 400}, 75.f, player->get_pos()));
}

std::shared_ptr<State> GameState::update(sf::Time const& time, sf::RenderWindow const& window) {
    game.update(time);

    if (game.is_game_over)
        return std::make_shared<GameOverState>(game);

    // We pause the game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !window.hasFocus())
        return std::make_shared<MenuState>(shared_from_this());

    return nullptr;
}

void GameState::render(sf::RenderWindow& target) {
    game.render(target);
}