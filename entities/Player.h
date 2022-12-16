//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_PLAYER_H
#define TDP005_PLAYER_H

#include "Movable_Object.h"

/**
 * Represent a player
 */
class Player : public Movable_Object {
public:
    /**
     * Create the player
     * @param position The position the player should spawn at
     * @param speed The speed the player move by
     */
    Player(sf::Vector2f const& position, float speed);

    /**
     * Update the player
     * @param time The time since the last update
     * @param game A reference to the game
     */
    void update(sf::Time const& time, Game& game) override;

    int attack() override;

    /**
     * Get the position of the player
     * @return The position of the player
     */
    sf::Vector2f const& get_pos() const;

    /**
     * Get the current hp of the player
     * @return The amount of hp
     */
    int get_hp() const;

protected:
    /**
     * Load and set the animations for the player
     */
    void set_animations() override;
};


#endif //TDP005_PLAYER_H
