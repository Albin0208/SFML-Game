//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAME_H
#define TDP005_GAME_H


#include <memory>

#include "common.h"
#include "Wave.h"

class Player;
class Game_Object;

class Game {
public:
    Game();
    ~Game() = default;

    bool is_game_over{false};
    /**
     * Update the game
     *
     * @param time The time since last update
     */
    virtual void update(sf::Time const& time, sf::RenderWindow const& window);

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
    void add(std::shared_ptr<Game_Object> const& object);

    /**
     * Check what object a object collides with
     *
     * @param obj The object to check for collision on
     * @return A vector of the the object collided with
     */
    vector<std::shared_ptr<Game_Object>> collides_with(Game_Object& obj) const;

    /**
     * Get a reference to the player position
     *
     * @return The player position
     */
    sf::Vector2f const& get_player_pos() const;

    /**
     * Tell the game that a enemy has been killed
     */

    void enemy_killed();

    sf::RenderWindow* window;

    int get_points() const;

    void add_points(int points);

private:
    vector<std::shared_ptr<Game_Object>> objects;
    Wave wave;
    sf::Clock survived_clock;

    sf::Time time_survived;

    sf::Font font;
    int points;
};


#endif //TDP005_GAME_H
