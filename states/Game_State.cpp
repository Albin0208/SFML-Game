//
// Created by albin on 2022-12-01.
//

#include <iostream>
#include "Game_State.h"
#include "Menu_State.h"
#include "../entities/Player.h"
#include "Game_Over_State.h"
#include "../utility/Texture_Manager.h"

Game_State::Game_State() {
    background.setTexture(*Texture_Manager::get("background.png"));
}

std::shared_ptr<State> Game_State::update(sf::Time const& time, sf::RenderWindow& window) {
    game.set_window(window);
    game.update(time);

    if (game.is_game_over)
        return std::make_shared<Game_Over_State>(game);

    // We pause the game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !window.hasFocus())
        return std::make_shared<Menu_State>(shared_from_this());

    return nullptr;
}

void Game_State::render(sf::RenderWindow& target) {
//    std::cout << background.getScale().x << std::endl;
    target.draw(background);
    game.render(target);
}