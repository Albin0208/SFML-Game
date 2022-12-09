//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAME_STATE_H
#define TDP005_GAME_STATE_H


#include "State.h"
#include "../Game.h"

class Game_State : public State {
public:
    Game_State();

    /**
     * Update the Game_State
     *
     * @param time Time since last update
     * @return A pointer to a state
     */
    std::shared_ptr<State> update(const sf::Time& time, sf::RenderWindow& window) override;

    /**
     * Render the Game_State
     * @param target Where to render
     */
    void render(sf::RenderWindow& target) override;
private:
    Game game;
};


#endif //TDP005_Game_State_H
