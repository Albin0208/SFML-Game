//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_MOVABLE_OBJECT_H
#define TDP005_MOVABLE_OBJECT_H


#include "Game_Object.h"
#include "Animation_Manager.h"

class Movable_Object : public Game_Object {
public:
    Movable_Object(const sf::Vector2f &position, float speed);
    ~Movable_Object() override = default;

    void update(const sf::Time &time, Game &game) override = 0;
    void render(sf::RenderWindow &window) override;

    /**
     * Make the object attack
     *
     * @return How much damage the attack did
     */
    virtual int attack() = 0;

protected:
    /**
     * Set up all the animation for the movable object
     */
    virtual void set_animations() = 0;

    sf::Clock attack_timer;
    int32_t attack_timer_max{};
    bool face_right;
    float speed;
    std::string type;
    Animation_Manager animation_manager;
};


#endif //TDP005_MOVABLE_OBJECT_H
