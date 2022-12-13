//
// Created by albin on 2022-12-05.
//

#include <iostream>
#include "Slow_Enemy.h"
#include "../../utility/Texture_Manager.h"
#include "../Projectile.h"
#include "../Player.h"
#include "../Obstacle.h"

Slow_Enemy::Slow_Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos)
    : Enemy(position, speed, player_pos, 10, 100, 5) {
    set_animations();
    attack_timer_max = 1500;
    sprite.setScale({1.f, 1.f});

    animation_manager.play("walk", sprite);

    hitbox.setSize({sprite.getGlobalBounds().width / 1.8f, sprite.getGlobalBounds().height / 1.3f});
}

void Slow_Enemy::update(sf::Time const& time, Game& game) {

    sf::Vector2f dir{player_pos - hitbox.getPosition()};

    dir /= static_cast<float>(sqrt(pow(dir.x, 2) + pow(dir.y, 2)));

    // Move if we are alive
    if (health > 0)
        position += speed * dir * time.asSeconds();

    if (dir.x > 0 || dir.y != 0 && face_right) {
        sprite.setOrigin(0.f, 0.f);
        sprite.setScale({1.f, 1.f});
        face_right = true;
        type = "walk";
    }
    if (dir.x < 0 || dir.y != 0 && !face_right) {
        sprite.setOrigin(198.4f, 0.f);
        sprite.setScale({-1.f, 1.f});
        face_right = false;
        type = "walk";
    }

    if (attacking) {
        animation_manager.play("attack", sprite, true);
        if (animation_manager.is_done("attack"))
            attacking = false;
    }
    else
        animation_manager.play(type, sprite);

    hitbox.setPosition(position);
    sprite.setPosition({hitbox.getPosition().x - hitbox.getSize().x / 2.4f, hitbox.getPosition().y - hitbox.getSize().y / 4});

    for (auto& o : game.collides_with(*this)) {
        // Make sure that we are not playing death animation
        if (health > 0) {
            if (auto e = dynamic_cast<Player*>(o.get())) {
                e->take_damage(attack());

                position = hitbox.getPosition() - ((dir * speed * time.asSeconds()));
                hitbox.setPosition(position);
            }

            if (auto e = std::dynamic_pointer_cast<Obstacle>(o)) {
                // Not able to pass through an obstacle
                obstacle_collision(e.get());
            }
        }
    }


    Enemy::update(time, game);
}

int Slow_Enemy::attack() {
    if (attack_timer.getElapsedTime().asMilliseconds() > attack_timer_max) {
        attacking = true;
        attack_timer.restart();
        return damage;
    }
    return 0;
}

void Slow_Enemy::set_animations() {
    animation_manager.add_animation("walk", Texture_Manager::get("slow_enemy.png"),
                                    18, 3 / 60.f);
    animation_manager.add_animation("attack", Texture_Manager::get("mino_attack2.png"),
                                    11, 3 / 60.f);
    animation_manager.add_animation("dying", Texture_Manager::get("dying_slow.png"),
                                    15, 3 / 60.f);
}