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

    virtual void update(sf::Time const& time, sf::RenderWindow& window);
    virtual void render(sf::RenderWindow& target);

    void add(std::shared_ptr<GameObject> object);

private:
    std::vector<std::shared_ptr<GameObject>> objects;
};


#endif //TDP005_GAME_H
