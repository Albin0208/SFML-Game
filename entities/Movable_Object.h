//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_MOVABLE_OBJECT_H
#define TDP005_MOVABLE_OBJECT_H


#include "Game_Object.h"
#include "../utility/Animation_Manager.h"
#include "Obstacle.h"

class Movable_Object : public Game_Object {
public:
    /**
     * Create a movable object
     * @param position The position to spawn at
     * @param speed
     */
    Movable_Object(const sf::Vector2f &position, float speed, float single_sprite_width = 0);
    ~Movable_Object() override = default;

    void update(const sf::Time &time, Game &game) override = 0;
    void render(sf::RenderWindow &window) override;

    /**
     * Make the object attack
     *
     * @return How much damage the attack did
     */
    virtual int attack() = 0;

    /**
     * Make the object take damage
     * @param damage The amount to take damage by
     */
    void take_damage(int damage);

    /**
     * Handle collision with an obstacle
     * @param obstacle The obstacle we are colliding with
     */
    void obstacle_collision(Obstacle* obstacle);

protected:
    /**
     * Set up all the animation for the movable object
     */
    virtual void set_animations() = 0;

    void handle_animation(sf::Vector2f& dir);

    sf::Clock attack_timer;
    float attack_timer_max;
    bool face_right;
    float speed;
    bool attacking;
    int health;

    float single_sprite_width;

    sf::Clock dmg_clock;
    std::string animation_type;
    Animation_Manager animation_manager;
};


#endif //TDP005_MOVABLE_OBJECT_H
