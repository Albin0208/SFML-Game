//
// Created by albin on 2022-12-01.
//

//#include <iostream>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "enemies/Enemy.h"
#include "Texture_Manager.h"

Game::Game() : window{nullptr}, points{0} {
    font.loadFromFile(FONT_PATH);

    // Preload enemy textures
    Texture_Manager::get("range_enemy_blue.png");
    Texture_Manager::get("range_attack_blue.png");
    Texture_Manager::get("dying_range.png");
    Texture_Manager::get("slow_enemy.png");
    Texture_Manager::get("mino_attack2.png");
    Texture_Manager::get("dying_slow.png");

    player = std::make_shared<Player>(sf::Vector2f{50, 50}, 300.f);
    add(player);

    back.setSize({300, 25});
    back.setFillColor(sf::Color::Red);
    back.setPosition({ 90.f, HEIGHT - 40});
    back.setOutlineThickness(2.f);
    back.setOutlineColor(sf::Color::White),
    bar = back;
    bar.setSize({298, 25});
    bar.setFillColor(sf::Color::Green);

    // Restart the survived clock to get time from after loading is done
    survived_clock.restart();
}

void Game::update(sf::Time const& time) {
    if (wave.is_over()) {
        vector<shared_ptr<Game_Object>>& tmp{wave.create(player->get_pos())};

        objects.reserve(tmp.size());
        // Move all the enemies to the object vector
        std::move(tmp.begin(), tmp.end(), std::back_inserter(objects));
    }

    for (size_t i{}; i < objects.size(); ++i) {
        if (objects[i] != nullptr) {
            objects[i]->update(time, *this);

            // If object is dead remove it
            if (!objects[i]->is_alive()) {
                objects.erase(objects.begin() + i);
                --i;
            }
        }
    }
}

void Game::render(sf::RenderWindow& target) {
    for (auto const& o : objects) {
        if (o != nullptr)
            o->render(target);
    }

    sf::Text point_text{"Points: " + std::to_string(points), font, 40};
    point_text.setPosition(15.f, 0.f);
    time_survived = survived_clock.getElapsedTime();
    target.draw(point_text);
    int minutes{static_cast<int>(time_survived.asSeconds() / 60)};
    int seconds{static_cast<int>(time_survived.asSeconds() - minutes * 60)};

    point_text.setString(std::to_string(minutes) + ":" + std::to_string(seconds));
    point_text.setOrigin(point_text.getGlobalBounds().width / 2, 0.f);
    point_text.setPosition((WIDTH / 2), 0.f);
    target.draw(point_text);

    point_text.setOrigin(0.f, 0.f);
    point_text.setString("Wave: " + std::to_string(wave.get_wave()));
    point_text.setPosition((WIDTH) - point_text.getGlobalBounds().width - 15.f, 0.f);
    target.draw(point_text);

    bar.setScale({static_cast<float>(player->get_hp()) / 100.f, 1.f});

    sf::Sprite sprite{*Texture_Manager::get("player_angel2.png"), sf::IntRect{900, 0, 900, 900}};
    sprite.setScale({0.1f, 0.1f});
    sprite.setPosition(back.getPosition());
    sprite.move({-sprite.getGlobalBounds().width, -sprite.getGlobalBounds().height / 2});
    target.draw(sprite);
    target.draw(back);
    target.draw(bar);

}

void Game::add(std::shared_ptr<Game_Object> const& object) {
    objects.push_back(object);
}

std::vector<std::shared_ptr<Game_Object>> Game::collides_with(Game_Object& obj) const{
    std::vector<std::shared_ptr<Game_Object>> collided_with{};

    for (auto const& o : objects) {
        // Check for self collision
        if (o == nullptr || o.get() == &obj)
            continue;

        // Check obj collides with any object
        if (obj.checkCollision(*o))
            collided_with.push_back(o);
    }

    return collided_with;
}

sf::Vector2f const& Game::get_player_pos() const {
    return dynamic_cast<Player*>(objects.at(0).get())->get_pos();
}

void Game::enemy_killed() {
    wave.enemy_killed();
}

int Game::get_points() const {
    return points;
}

void Game::add_points(int points_to_add) {
    points += points_to_add;
}