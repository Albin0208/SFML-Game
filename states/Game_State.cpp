//
// Created by albin on 2022-12-01.
//

#include "Game_State.h"
#include "Menu_State.h"
#include "../Player.h"
#include "Game_Over_State.h"

Game_State::Game_State() {
    // Create the player and add to game
    game.add(std::make_shared<Player>(sf::Vector2f{50, 50}, 300.f));
}

std::shared_ptr<State> Game_State::update(sf::Time const& time, sf::RenderWindow& window) {
    game.window = &window;
    game.update(time);

    if (game.is_game_over)
        return std::make_shared<Game_Over_State>(game);

    // We pause the game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !window.hasFocus())
        return std::make_shared<Menu_State>(shared_from_this());

    return nullptr;
}

void Game_State::render(sf::RenderWindow& target) {
    game.render(target);
}