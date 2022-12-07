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
    sprite.setTexture(*TextureManager::get("slow_enemy.png"));
    sprite.setScale({0.3f, 0.3f});
    //sprite.setTextureRect(animations.find("walk")->second.uv_rect);
    hitbox.setSize({sprite.getGlobalBounds().width / 1.8f, sprite.getGlobalBounds().height / 1.3f});
}

void SlowEnemy::update(sf::Time const& time, Game& game) {
    sf::Vector2f dir{player_pos - hitbox.getPosition()};

    dir /= static_cast<float>(sqrt(pow(dir.x, 2) + pow(dir.y, 2)));

    position += speed * dir * time.asSeconds();

    if (dir.x > 0)
        face_right = true;
    else if (dir.x < 0)
        face_right = false;

//    if (animations.find("attack")->second.is_running()) {
//        sprite.setTexture(*TextureManager::get("mino_attack2.png"));
//        //animations.find("attack")->second.update(0, time.asSeconds(), face_right);
//        sprite.setTextureRect(animations.find("attack")->second.uv_rect);
//    } else {
//        sprite.setTexture(*TextureManager::get("slow_enemy.png"));
//        //animations.find("walk")->second.update(0, time.asSeconds(), face_right);
//        sprite.setTextureRect(animations.find("walk")->second.uv_rect);
//    }

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
        //animations.find("attack")->second.run();
        attack_timer.restart();
        return 5;
    }

    return 0;
}

void SlowEnemy::set_animations() {
    animations.insert(std::make_pair("walk", Animation{TextureManager::get("slow_enemy.png"),
                                                       sf::Vector2u{18, 1}, 1.f}));
    animations.insert(std::make_pair("attack", Animation{TextureManager::get("mino_attack2.png"),
                                                       sf::Vector2u{11, 1}, 0.7f}));
}
