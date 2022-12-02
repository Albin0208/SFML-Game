//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_GAMEOBJECT_H
#define TDP005_GAMEOBJECT_H


#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class GameObject {
public:
    explicit GameObject(sf::Vector2f const& position);
    virtual ~GameObject() = default;

    /**
     * Update the gameobject
     * @param time The time since last update
     * @param window A reference to the window
     */
    virtual void update(sf::Time const& time, sf::RenderWindow& window) = 0;

    /**
     * Render the game object
     *
     * @param window The window to render to
     */
    virtual void render(sf::RenderWindow& window) = 0;

protected:
    sf::RectangleShape shape;
    sf::Vector2f position;
};


#endif //TDP005_GAMEOBJECT_H
