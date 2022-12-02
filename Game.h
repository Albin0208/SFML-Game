//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAME_H
#define TDP005_GAME_H


#include <memory>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "GameObject.h"

class Game {
public:
    Game();
    virtual ~Game() = default;

    /**
     * Update the game
     *
     * @param time The time since last update
     * @param window A reference to the window
     */
    virtual void update(sf::Time const& time);

    /**
     * Render the game
     *
     * @param target Where to render the game
     */
    virtual void render(sf::RenderWindow& target);

    /**
     * Add a gameobject to the game
     * @param object The object to add
     */
    void add(std::shared_ptr<GameObject> const& object);

private:
    std::vector<std::shared_ptr<GameObject>> objects;
};


#endif //TDP005_GAME_H
