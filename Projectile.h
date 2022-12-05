//
// Created by ingva on 2022-12-05.
//

#ifndef TDP005_PROJECTILE_H
#define TDP005_PROJECTILE_H
#include "MovableObject.h"


class Projectile : public MovableObject{
public:
    Projectile(const sf::Vector2f &position, float speed, sf::Vector2f const& direction,int damage);
    //~Projectile() override = default;

    void update(const sf::Time &time, Game &game, sf::RenderWindow const& window) override;
    void render(sf::RenderWindow &window) override;
    int attack() override;
protected:
    sf::Vector2f direction;
    int damage;
};






#endif //TDP005_PROJECTILE_H
