//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAMEOBJECT_H
#define TDP005_GAMEOBJECT_H


#include "common.h"
#include "SFML/System.hpp"
#include "Game.h"
#include "Animation.h"

class GameObject {
public:
    GameObject(sf::Vector2f const& position);
    virtual ~GameObject() = default;

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
    virtual bool checkCollision(GameObject const& obj);

    bool is_alive() const;

protected:
    sf::RectangleShape hitbox;
    sf::Vector2f position;
    bool alive;
    sf::Sprite sprite;
};


#endif //TDP005_GAMEOBJECT_H
