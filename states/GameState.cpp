//
// Created by albin on 2022-12-01.
//

#include "GameState.h"
#include "MenuState.h"
#include "../Player.h"
#include "../enemies/SlowEnemy.h"
#include "../Projectile.h"

GameState::GameState() {
    // Create the player and add to game
    shared_ptr<Player> player{std::make_shared<Player>(sf::Vector2f{50, 50}, 300.f)};
    game.add(player);
    game.add(std::make_shared<SlowEnemy>(sf::Vector2f{200, 400}, 0.f, player->get_pos()));
    //game.add(std::make_shared<Projectile>(sf::Vector2f{400,500},0.0f,sf::Vector2f{1,1},40));
}

std::shared_ptr<State> GameState::update(sf::Time const& time, sf::RenderWindow const& window) {
    game.update(time, window);

    // We pause the game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !window.hasFocus())
        return std::make_shared<MenuState>(shared_from_this());

    return nullptr;
}

void GameState::render(sf::RenderWindow& target) {
    game.render(target);
}