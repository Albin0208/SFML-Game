//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAMESTATE_H
#define TDP005_GAMESTATE_H


#include "State.h"
#include "../Game.h"

class GameState : public State {
public:
    GameState();

    /**
     * Update the gamestate
     *
     * @param time Time since last update
     * @return A pointer to a state
     */
    std::shared_ptr<State> update(const sf::Time& time, sf::RenderWindow const& window) override;

    /**
     * Render the gamestate
     * @param target Where to render
     */
    void render(sf::RenderWindow& target) override;
private:
    Game game;
};


#endif //TDP005_GAMESTATE_H
