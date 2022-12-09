//
// Created by ingva on 2022-12-05.
//
#include <iostream>
#include "Projectile.h"
#include "enemies/Enemy.h"
#include "enemies/Slow_Enemy.h"
#include "enemies/Ranged_Enemy.h"
#include "Player.h"

Projectile::Projectile(sf::Vector2f const& position, float speed, sf::Vector2f const& direction, int damage, Objects_to_hit what_to_hit) :
        Movable_Object(position, speed), direction{direction}, damage{damage}, what_to_hit{what_to_hit} {

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
        //Do some stuff on collision depending on what type it is
        switch (what_to_hit) {
            case Objects_to_hit::all_enemies:
                if (auto e = dynamic_cast<Enemy*>(o.get())) {
                    // Make enemy take damage
                    e->take_damage(damage);
                    // Kill the projectile
                    alive=false;
                }
                break;
            case Objects_to_hit::all_players:
                if (auto e = dynamic_cast<Player*>(o.get())) {
                    // Make enemy take damage
                    e->take_damage(damage);
                    // Kill the projectile
                    alive=false;
                }
                break;
            case Objects_to_hit::slowerenemy:
                if (auto e = dynamic_cast<Slow_Enemy*>(o.get())) {
                    // Make enemy take damage
                    e->take_damage(damage);
                    // Kill the projectile
                    alive=false;
                }
                break;
            case Objects_to_hit::rangedenemy:
                if (auto e = dynamic_cast<Ranged_Enemy*>(o.get())) {
                    // Make enemy take damage
                    e->take_damage(damage);
                    // Kill the projectile
                    alive=false;
                }
                break;
        }

    }
}

void Projectile::set_animations() {

}

void Projectile::render(sf::RenderWindow& window) {
    window.draw(hitbox);
    window.draw(sprite);
}

int Projectile::attack() {
    return damage;
}