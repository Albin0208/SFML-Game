//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAME_H
#define TDP005_GAME_H


#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class Game {
public:
    Game();
    virtual ~Game();

    virtual void update(sf::Time const& time);
    virtual void render(sf::RenderWindow& target);
};


#endif //TDP005_GAME_H
