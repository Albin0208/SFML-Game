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
    virtual int attack(sf::Time const& time) = 0;
protected:
    virtual void set_animations() = 0;

    bool face_right;
    float speed;
    Animation current_animation{};
    std::map<std::string, Animation> animations;
    std::string type;
    AnimationManager animation_manager;
};


#endif //TDP005_MOVABLEOBJECT_H
