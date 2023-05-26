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
     * Create a obstacle
     *
     * @param position The position of the obstacle
     * @param texture What texture we are going to use
     * @param texture_num Which texture number in the texture we want
     */
    Obstacle(sf::Vector2f const& position, sf::Texture* texture, int texture_num);

    /**
     * Perform update on the obstacle
     *
     * @param time The time since last update
     * @param game A reference to the game
     */
    void update(sf::Time const& time, Game& game) override;

    /**
     * Render the obstacle to the window
     * @param window The window to render to
     */
    void render(sf::RenderWindow& window) override;

    /**
     * Get the position of the obstacle
     *
     * @return The position of the obstacle
     */
    sf::Vector2f get_pos() const;

    /**
     * Get the size of the obstacle
     *
     * @return The size
     */
    sf::Vector2f get_size() const;
};


#endif //TDP005_OBSTACLE_H
