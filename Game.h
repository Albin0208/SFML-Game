//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAME_H
#define TDP005_GAME_H


#include <memory>

#include "utility/common.h"
#include "Wave.h"

class Player;
class Game_Object;

enum Objects_to_hit { all_enemies, all_players, slowerenemy, rangedenemy};

/**
 * The game class responsible for updating and rendering the game
 */
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
    void add(std::shared_ptr<Game_Object> const& object);

    /**
     * Check what object a object collides with
     *
     * @param obj The object to check for collision on
     * @return A vector of the the object collided with
     */
    vector<std::shared_ptr<Game_Object>> collides_with(Game_Object& obj) const;

    /**
     * Tell the game that a enemy has been killed
     */
    void enemy_killed();

    /**
     * Get the points collected during the game
     * @return The points
     */
    int get_points() const;

    /**
     * Add points to the collected points
     * @param points How many points to add
     */
    void add_points(int points);

    sf::RenderWindow const* get_window() const;

    void set_window(sf::RenderWindow& window);

private:
    void spawn_obstacles();

    vector<std::shared_ptr<Game_Object>> objects;
    Wave wave;
    sf::Clock survived_clock;
    shared_ptr<Player> player;

    sf::Time time_survived;

    sf::Font font;
    int points;

    // Healthbar components
    sf::RectangleShape back;
    sf::RectangleShape bar;

    sf::Sprite player_img;

    sf::RenderWindow* window;
};


#endif //TDP005_GAME_H
