//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_PLAYER_H
#define TDP005_PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
public:
    explicit Player(sf::Vector2f const& position);

    void update(sf::Time const& time, Game& game) override;
    void render(sf::RenderWindow& window) override;

private:
    float speed{};
};


#endif //TDP005_PLAYER_H
