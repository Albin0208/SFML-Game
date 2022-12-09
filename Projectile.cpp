//
// Created by ingva on 2022-12-05.
//
#include <iostream>
#include "Projectile.h"
#include "enemies/Enemy.h"
#include "enemies/Slow_Enemy.h"
#include "enemies/Ranged_Enemy.h"
#include "Player.h"
#include "Texture_Manager.h"

Projectile::Projectile(sf::Vector2f const& position, float speed, sf::Vector2f const& direction,
                       int damage, Objects_to_hit what_to_hit, sf::Color color) :
        Movable_Object(position, speed), direction{direction}, damage{damage}, what_to_hit{what_to_hit} {
    set_animations();
    sprite.setScale(1, 1);
    sf::Vector2f sprite_size{Texture_Manager::get("fireball1.png")->getSize()};
    animation_manager.play("shoot", sprite);

//    sprite_size.x /= 5;
//    sprite_size.y /= 5;
    sprite.setOrigin({sprite_size.x  / 5 / 2, sprite_size.y / 5 / 2});

    sprite.setRotation(static_cast<float>(atan2(direction.y, direction.x) * (180 / M_PI)));

    hitbox.setSize({sprite.getLocalBounds().width / 3.f, sprite.getLocalBounds().height / 2.f});
}


void Projectile::update(sf::Time const& time, Game& game) {
    position += direction * speed * time.asSeconds();

    // Check for moving out if window
    // Left / top collision
    if (position.x < 0.f || position.y < 0.f)
        alive=false;
    // Right / bottom collision
    if (position.x + hitbox.getGlobalBounds().width > WIDTH ||
        position.y + hitbox.getGlobalBounds().height > HEIGHT)
        alive=false;

    animation_manager.play("shoot", sprite);

    hitbox.setPosition(position);
    sprite.setPosition({hitbox.getPosition().x - hitbox.getGlobalBounds().width / 2, hitbox.getPosition().y - hitbox.getGlobalBounds().height / 2});

    if (direction.x > 0)
        sprite.move({hitbox.getGlobalBounds().width, 0});
    if (direction.x < 0)
        sprite.move({hitbox.getGlobalBounds().width, hitbox.getGlobalBounds().height});
    if (direction.y > 0)
        sprite.move({hitbox.getGlobalBounds().width -10, 0});
    if (direction.y < 0)
        sprite.move({0, hitbox.getGlobalBounds().height});

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
    sf::Texture* texture{Texture_Manager::get("fireball1.png")};

    if (what_to_hit == Objects_to_hit::all_players)
        texture= Texture_Manager::get("fireball_blue.png");
    animation_manager.add_animation("shoot", texture,
                                    sf::Vector2u{5, 1}, 2 / 60.f);
}

int Projectile::attack() {
    return damage;
}