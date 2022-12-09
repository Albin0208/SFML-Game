//
// Created by albin on 2022-12-01.
//

//#include <iostream>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "enemies/Enemy.h"

Game::Game() : window{nullptr}, points{0} {
    font.loadFromFile(FONT_PATH);
}

void Game::update(sf::Time const& time) {

    if (wave.is_over()) {
        vector<shared_ptr<Game_Object>>& tmp{wave.create(get_player_pos())};

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
    time_survived += time;
}

void Game::render(sf::RenderWindow& target) {
    for (auto const& o : objects) {
        if (o != nullptr)
            o->render(target);
    }

    sf::Text point_text{"Points: " + std::to_string(points), font, 40};
    point_text.setPosition(15.f, 0.f);

    target.draw(point_text);
    int minutes{static_cast<int>(time_survived.asSeconds() / 60)};
    int seconds{static_cast<int>(time_survived.asSeconds() - minutes * 60)};
    std::string s{std::to_string(minutes) + ":" + std::to_string(seconds)};

    point_text.setString(s);
    point_text.setOrigin(point_text.getGlobalBounds().width / 2, 0.f);
    point_text.setPosition((WIDTH / 2), 0.f);
    target.draw(point_text);

    point_text.setOrigin(0.f, 0.f);
    point_text.setString("Wave: " + std::to_string(wave.get_wave()));
    point_text.setPosition((WIDTH) - point_text.getGlobalBounds().width - 15.f, 0.f);
    target.draw(point_text);
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