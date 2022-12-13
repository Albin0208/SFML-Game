//
// Created by albin on 2022-12-12.
//

#ifndef TDP005_OBSTACLE_H
#define TDP005_OBSTACLE_H

#include "../utility/common.h"
#include "Game_Object.h"

class Obstacle : public Game_Object {
public:
    /**
     * Create a new obstacle
     * @param position The position the obstacle should spawn at
     * @param texture What texture the obstacle should be represented by
     * @param texture_num What number of the texture sheet the obstacle should use
     */
    Obstacle(sf::Vector2f const& position, sf::Texture* texture, int texture_num);

    /**
     * Update the obstacle
     * @param time The time since last update
     * @param game A reference to the game
     */
    void update(sf::Time const& time, Game& game) override;

    /**
     * Render the obstacle
     * @param window The window to render to
     */
    void render(sf::RenderWindow& window) override;
};


#endif //TDP005_OBSTACLE_H
