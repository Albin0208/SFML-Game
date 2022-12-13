//
// Created by ingva on 2022-12-09.
//

#include "Ranged_Enemy.h"
#include "../Projectile.h"
#include "../../utility/Texture_Manager.h"


Ranged_Enemy::Ranged_Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos)
                            : Enemy(position, speed, player_pos, 5, 60, 5) {
    set_animations();
    attack_timer_max = 2000;
    sprite.setScale({1.f, 1.f});

    animation_manager.play("walk", sprite);

    hitbox.setSize({sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 1.5f});
}

void Ranged_Enemy::update(sf::Time const& time, Game& game) {
    sf::Vector2f diff{player_pos - hitbox.getPosition()};

    float distance{sqrtf(powf(diff.x, 2) + powf(diff.y, 2))};

    sf::Vector2f dir{player_pos - hitbox.getPosition()};
    dir /= static_cast<float>(sqrt(pow(dir.x, 2) + pow(dir.y, 2)));

    // Move if we are alive and in range
    if (distance > 200.f && health > 0) {
        position += speed * dir * time.asSeconds();
    }

    // Make a ranged attack
    if (distance < 500.f)
        if (attack_timer.getElapsedTime().asMilliseconds() > attack_timer_max) {
            //&& (player_pos - hitbox.getPosition()-position) < 100.0f      add attack range to ranged enemies
            attack_timer.restart();
            attacking=true;

            sf::Vector2f projectile_dir{player_pos - position};

            // Normalize the projectile-direction-vector
            projectile_dir /= static_cast<float>(sqrt(pow(projectile_dir.x, 2) + pow(projectile_dir.y, 2)));

            game.add(std::make_shared<Projectile>(position, 300.f, projectile_dir,
                                                  5, Objects_to_hit::all_players,
                                                  sf::Color(0,213,200)));
        }

    if (dir.x > 0 || dir.y != 0 && face_right) {
        sprite.setOrigin(0.f, 0.f);
        sprite.setScale({1.f, 1.f});
        face_right = true;
        type = "walk";
    }
    if (dir.x < 0 || dir.y != 0 && !face_right) {
        sprite.setOrigin(135.f, 0.f);
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

    Enemy::update(time, game);
}

int Ranged_Enemy::attack() {
    if (attack_timer.getElapsedTime().asMilliseconds() > attack_timer_max) {
        attacking = true;
        attack_timer.restart();
        return 5;
    }

    return 0;
}

void Ranged_Enemy::set_animations() {
    animation_manager.add_animation("walk", Texture_Manager::get("range_enemy_blue.png"),
                                    12, 3 / 60.f);
    animation_manager.add_animation("attack", Texture_Manager::get("range_attack_blue.png"),
                                    18, 2 / 60.f);
    animation_manager.add_animation("dying", Texture_Manager::get("dying_range.png"),
                                    15, 2 / 60.f);
}
