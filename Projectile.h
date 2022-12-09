//
// Created by ingva on 2022-12-05.
//

#ifndef TDP005_PROJECTILE_H
#define TDP005_PROJECTILE_H
#include "Movable_Object.h"


class Projectile : public Movable_Object {
public:
    Projectile(sf::Vector2f const& position, float speed, sf::Vector2f const& direction, int damage);
    ~Projectile() override = default;

    void update(const sf::Time& time, Game& game) override;
    void render(sf::RenderWindow& window) override;
    int attack() override;

protected:
    void set_animations() override;

protected:
    sf::Vector2f direction;
    int damage;
};






#endif //TDP005_PROJECTILE_H
