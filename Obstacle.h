//
// Created by albin on 2022-12-12.
//

#ifndef TDP005_OBSTACLE_H
#define TDP005_OBSTACLE_H

#include "common.h"
#include "Game_Object.h"

class Obstacle : public Game_Object {
public:
    Obstacle(sf::Vector2f const& position, sf::Texture* texture);

    void update(sf::Time const& time, Game& game) override;

    void render(sf::RenderWindow& window) override;

    sf::CircleShape const& get_shape() const;

    sf::Vector2f get_pos() const;

    sf::Vector2f get_size() const;

private:
    sf::CircleShape shape;
};


#endif //TDP005_OBSTACLE_H
