//
// Created by ingva on 2022-12-05.
//
#include <iostream>
#include "Projectile.h"
#include "enemies/Enemy.h"

Projectile::Projectile(sf::Vector2f const& position, float speed, sf::Vector2f const& direction, int damage) :
        MovableObject(position, speed), direction{direction}, damage{damage} {

    hitbox.setSize(sf::Vector2f{5, 5});
    hitbox.setPosition(position);
    hitbox.setFillColor(sf::Color::White);
}


void Projectile::update(sf::Time const& time, Game& game) {
    position += direction * speed * time.asSeconds();

    // Check for moving out if window
    // Left collision
    if (position.x < 0.f)
        alive=false;
    // Top collision
    if (position.y < 0.f)
        alive=false;
    // Right collision
    if (position.x + hitbox.getGlobalBounds().width > WIDTH)
        alive=false;
    // Bottom collision
    if (position.y + hitbox.getGlobalBounds().height > HEIGHT)
        alive=false;

    hitbox.setPosition(position);
    sprite.setPosition(position);

    for (auto& o : game.collides_with(*this)) {
        // TODO: Do some stuff on collision depending on what type it is
        if (auto e = dynamic_cast<Enemy*>(o.get())) {
            // Kill the projectile
            e->take_damage(damage);
            alive=false;
        }
    }
}

void Projectile::set_animations() {

}

void Projectile::render(sf::RenderWindow& window) {
    window.draw(hitbox);
    window.draw(sprite);
}

int Projectile::attack(sf::Time const& time) {
    return damage;
}