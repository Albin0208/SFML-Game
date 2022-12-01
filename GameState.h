//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAMESTATE_H
#define TDP005_GAMESTATE_H


#include "State.h"
#include "Game.h"

class GameState : public State {
public:
    GameState();

    std::shared_ptr<State> update(const sf::Time& time) override;

    void render(sf::RenderWindow& target) override;
private:
    Game game;
};


#endif //TDP005_GAMESTATE_H
