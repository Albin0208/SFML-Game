//
// Created by ingva on 2022-12-09.
//

#ifndef TDP005_RANGED_ENEMY_H
#define TDP005_RANGED_ENEMY_H

#include "SFML/System/Vector2.hpp"
#include "../../Game.h"
#include "Enemy.h"

class Ranged_Enemy : public Enemy {
public:
    /**
     * Create a enemy
     * @param position The enemy position
     * @param speed What speed it should move by
     * @param player_pos Where the player is located
     */
    Ranged_Enemy(sf::Vector2f const& position1, float speed1, sf::Vector2f const& playerPos);

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

private:
    float range;
};

#endif //TDP005_RANGED_ENEMY_H
