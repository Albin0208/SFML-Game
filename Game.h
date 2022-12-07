//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAME_H
#define TDP005_GAME_H


#include <memory>

#include "common.h"
#include "Wave.h"
//#include "SFML/System.hpp"

class Player;
class GameObject;

class Game {
public:
    Game() = default;

    bool is_game_over{false};
    /**
     * Update the game
     *
     * @param time The time since last update
     */
    virtual void update(sf::Time const& time);

    /**
     * Render the game
     *
     * @param target Where to render the game
     */
    virtual void render(sf::RenderWindow& target);

    /**
     * Add a gameobject to the game
     * @param object The object to add
     */
    void add(std::shared_ptr<GameObject> const& object);

    /**
     * Check what object a object collides with
     *
     * @param obj The object to check for collision on
     * @return A vector of the the object collided with
     */
    vector<std::shared_ptr<GameObject>> collides_with(GameObject& obj);

    sf::Vector2f const& get_player_pos();
private:
    vector<std::shared_ptr<GameObject>> objects;
    Wave wave;
};


#endif //TDP005_GAME_H
