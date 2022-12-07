//
// Created by albin on 2022-12-05.
//

#include "SlowEnemy.h"
#include "../TextureManager.h"

#include <utility>
#include <iostream>

SlowEnemy::SlowEnemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos)
    : Enemy(position, speed, player_pos) {
    set_animations();
    hitbox.setSize({100, 135});
    //sprite.setTexture(*TextureManager::get("slow_enemy.png"));
    sprite.setScale({0.3f, 0.3f});

    animation_manager.play("walk", sprite);
    //sprite.setTextureRect(animations.find("walk")->second.uv_rect);
    hitbox.setSize({sprite.getGlobalBounds().width / 1.8f, sprite.getGlobalBounds().height / 1.3f});
}

void SlowEnemy::update(sf::Time const& time, Game& game) {
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



    for (auto& o : game.collides_with(*this)) {
        // TODO: Take damage from player projectiles

        if (health <= 0)
            alive = false;
//        position = hitbox.getPosition() - dir * speed * time.asSeconds();
//        hitbox.setPosition(position);
    }
}

int SlowEnemy::attack(sf::Time const& time) {
    if (attack_timer.getElapsedTime().asMilliseconds() > attack_timer_max) {
        std::cout << "kaksdkasdkaskd";
        attacking = true;
        attack_timer.restart();
        return 5;
    }

    return 0;
}

void SlowEnemy::set_animations() {
    animation_manager.add_animation("walk", TextureManager::get("slow_enemy.png"),
                                    sf::Vector2u{18, 1}, 3 / 60.f);
    animation_manager.add_animation("attack", TextureManager::get("mino_attack2.png"),
                                    sf::Vector2u{11, 1}, 3 / 60.f);
}
