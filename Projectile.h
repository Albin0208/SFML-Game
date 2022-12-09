//
// Created by ingva on 2022-12-05.
//

#ifndef TDP005_PROJECTILE_H
#define TDP005_PROJECTILE_H
#include "Movable_Object.h"
#include "Object_type.h"


class Projectile : public Movable_Object {
public:
    Projectile(sf::Vector2f const& position, float speed, sf::Vector2f const& direction,
               int damage, Objects_to_hit what_to_hit, sf::Color color = sf::Color::White);
    ~Projectile() override = default;

    void update(const sf::Time& time, Game& game) override;
    int attack() override;

protected:
    void set_animations() override;

protected:
    sf::Vector2f direction;
    int damage;
    Objects_to_hit what_to_hit;
};






#endif //TDP005_PROJECTILE_H
