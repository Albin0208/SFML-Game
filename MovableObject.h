//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_MOVABLEOBJECT_H
#define TDP005_MOVABLEOBJECT_H


#include "GameObject.h"
#include "AnimationManager.h"

class MovableObject : public GameObject {
public:
    MovableObject(const sf::Vector2f &position, float speed);
    ~MovableObject() override = default;

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
    AnimationManager animation_manager;
};


#endif //TDP005_MOVABLEOBJECT_H
