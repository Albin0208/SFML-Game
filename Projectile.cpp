//
// Created by ingva on 2022-12-05.
//
#include <iostream>
#include "Projectile.h"
#include "enemies/Enemy.h"

Projectile::Projectile(sf::Vector2f const& position, float speed, sf::Vector2f const& direction, int damage) :
MovableObject(position, speed), direction{direction}, damage {damage} {

    shape.setSize(sf::Vector2f{5, 5});
    shape.setPosition(position);
    shape.setFillColor(sf::Color::White);
}


void Projectile::update(sf::Time const& time, Game& game) {

    position += direction * speed * time.asSeconds();


    // Check for moving out if window
    // Left collision
    //if (position.x < 0.f)
        //kill/remove projectile
    // Top collision
    //if (position.y < 0.f)
        //kill/remove projectile
    // Right collision
    //if (position.x + shape.getGlobalBounds().width > WIDTH)
        //kill/remove projectile
    // Bottom collision
    //if (position.y + shape.getGlobalBounds().height > HEIGHT)
        //kill/remove projectile

    shape.setPosition(position);
    sprite.setPosition(position);

    for (auto& o : game.collides_with(*this)) {
        // TODO: Do some stuff on collision depending on what type it is
        if (auto e = dynamic_cast<Enemy*>(o.get())) {
            //göra skada på e
            std::cout << "träff" << std::endl;

            // Not able to pass through an enemy
//            position = shape.getPosition() - dir * speed * time.asSeconds();
//            shape.setPosition(position);
        }
    }
}

void Projectile::render(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(sprite);

}
int Projectile::attack() {
    return 0;
}