//
// Created by albin on 2022-12-12.
//

#ifndef TDP005_OBSTACLE_H
#define TDP005_OBSTACLE_H

#include "../utility/common.h"
#include "Game_Object.h"

class Obstacle : public Game_Object {
public:
    Obstacle(sf::Vector2f const& position, sf::Texture* texture, int texture_num);

    void update(sf::Time const& time, Game& game) override;

    void render(sf::RenderWindow& window) override;

    sf::Vector2f get_pos() const;

    sf::Vector2f get_size() const;
};


#endif //TDP005_OBSTACLE_H
