//
// Created by ingva on 2022-12-05.
//

#ifndef TDP005_PROJECTILE_H
#define TDP005_PROJECTILE_H
#include "Movable_Object.h"
#include "../Game.h"

/**
 * A object to represent a projectile int the game
 */
class Projectile : public Movable_Object {
public:
    /**
     * Create a projectile
     * @param position Where the projectile should spawn
     * @param speed What speed the projectile is fired with
     * @param direction The direction the projectile should move in
     * @param damage How much damage the projectile does
     * @param what_to_hit What object the projectile should hit
     */
    Projectile(sf::Vector2f const& position, float speed, sf::Vector2f const& direction,
               int damage, Objects_to_hit what_to_hit);

    ~Projectile() override = default;

    /**
     * Update the projectile
     * @param time The time since last update
     * @param game A reference to the game
     */
    void update(const sf::Time& time, Game& game) override;
    int attack() override;

protected:
    /**
     * Load and set the animations for the projectile
     */
    void set_animations() override;

private:
    sf::Vector2f direction;
    int damage;
    Objects_to_hit what_to_hit;
};






#endif //TDP005_PROJECTILE_H
