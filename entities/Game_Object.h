//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAME_OBJECT_H
#define TDP005_GAME_OBJECT_H


#include "../utility/common.h"
#include "SFML/System.hpp"
#include "../Game.h"

class Game;

class Game_Object {
public:
    Game_Object(sf::Vector2f const& position);
    virtual ~Game_Object() = default;

    /**
     * Update the gameobject
     * @param time The time since last update
     * @param game A reference to the game world
     */
    virtual void update(sf::Time const& time, Game& game) = 0;

    /**
     * Render the game object
     *
     * @param window The window to render to
     */
    virtual void render(sf::RenderWindow& window) = 0;

    /**
     * Check for collision between this object and another
     * @param obj The object to check
     * @return If the object collide
     */
    virtual bool checkCollision(Game_Object const& obj);

    /**
     * Get if the current object is alive
     * @return If the object is alive
     */
    bool is_alive() const;

protected:
    sf::RectangleShape hitbox;
    sf::Vector2f position;
    sf::Sprite sprite;
//    sf::Texture texture;
    bool alive;
};


#endif //TDP005_GAME_OBJECT_H
