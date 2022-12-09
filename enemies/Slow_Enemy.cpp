//
// Created by albin on 2022-12-05.
//

#include <iostream>
#include "Slow_Enemy.h"
#include "../Texture_Manager.h"
#include "../Projectile.h"

Slow_Enemy::Slow_Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos)
    : Enemy(position, speed, player_pos, 10) {
    set_animations();
    attack_timer_max = 500;
    sprite.setScale({0.3f, 0.3f});

    animation_manager.play("walk", sprite);

    hitbox.setSize({sprite.getGlobalBounds().width / 1.8f, sprite.getGlobalBounds().height / 1.3f});
}

void Slow_Enemy::update(sf::Time const& time, Game& game) {
    sf::Vector2f dir{player_pos - hitbox.getPosition()};

    dir /= static_cast<float>(sqrt(pow(dir.x, 2) + pow(dir.y, 2)));

    position += speed * dir * time.asSeconds();

    if (dir.x > 0 || dir.y != 0 && face_right) {
        sprite.setOrigin(0.f, 0.f);
        sprite.setScale({0.3f, 0.3f});
        face_right = true;
        type = "walk";
    }
    if (dir.x < 0 || dir.y != 0 && !face_right) {
        sprite.setOrigin(720.f, 0.f);
        sprite.setScale({-0.3f, 0.3f});
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

//    for (auto& o : game.collides_with(*this)) {
//        // TODO: Take damage from player projectiles
//        if (auto e = dynamic_cast<Projectile*>(o.get())) {
//            health -= o.get()->attack(time);
//            std::cout << health << "\n";
//
////            if (health <= 0) {
////                std::cout << "dead" << "\n";
////                alive = false;
////                animation_manager.kill();
////            }
////        position = hitbox.getPosition() - dir * speed * time.asSeconds();
////        hitbox.setPosition(position);
//        }
//    }
    if (health <= 0) {
        alive = false;
        animation_manager.kill();
        game.enemy_killed();
        game.add_points(points);
    }
}

int Slow_Enemy::attack() {
    if (attack_timer.getElapsedTime().asMilliseconds() > attack_timer_max) {
        attacking = true;
        attack_timer.restart();
        return 5;
    }

    return 0;
}

void Slow_Enemy::set_animations() {
    animation_manager.add_animation("walk", Texture_Manager::get("slow_enemy.png"),
                                    sf::Vector2u{18, 1}, 3 / 60.f);
    animation_manager.add_animation("attack", Texture_Manager::get("mino_attack2.png"),
                                    sf::Vector2u{11, 1}, 3 / 60.f);
}

void Slow_Enemy::take_damage(int damage) {
    health -= damage;
}
