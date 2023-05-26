//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_SLOW_ENEMY_H
#define TDP005_SLOW_ENEMY_H


#include "Enemy.h"

class Slow_Enemy : public Enemy {
public:
    /**
     * Create a enemy
     * @param position The enemy position
     * @param speed What speed it should move by
     * @param player_pos Where the player is located
     */
    Slow_Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos);

    /**
     * Update the enemy
     *
     * @param time Time since last update
     * @param game A reference to the game
     */
    void update(const sf::Time &time, Game &game) override;

    /**
     * Perform a attack
     *
     * @return The damage of the attack
     */
    int attack() override;

protected:
    /**
     * Create and save the animations to the animation_manager
     */
    void set_animations() override;

};


#endif //TDP005_SLOW_ENEMY_H
