//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_ENEMY_H
#define TDP005_ENEMY_H

#include "../Movable_Object.h"

class Enemy : public Movable_Object {
public:
    /**
     * Create the enemy
     * @param position The position of the enemy
     * @param speed What speed it moves by
     * @param player_pos Where the player is located
     * @param points How many points it gives on death
     * @param health How much health it has
     * @param damage The damage it does on attacks
     * @param single_sprite_width How wide a single sprite is in the spritesheet
     */
    Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos,
          int points, int health, int damage, float single_sprite_width);

    ~Enemy() override = default;

    /**
     * Update the enemy
     *
     * @param time Time since last update
     * @param game A reference to the game
     */
    void update(sf::Time const& time, Game& game) override;

    /**
     * Draw the enemy to the window
     * @param window The window to draw to
     */
    void render(sf::RenderWindow& window) override;

    /**
     * Perform the attack
     * @return The amount of damage done
     */
    int attack() override = 0;

protected:
    /**
     * Create and save the animations to the animation_manager
     */
    void set_animations() override = 0;

    sf::Vector2f const& player_pos;
    int points;
    int damage;

private:
    sf::RectangleShape health_bar_background;
    sf::RectangleShape health_bar;

    int max_health;
};


#endif //TDP005_ENEMY_H
