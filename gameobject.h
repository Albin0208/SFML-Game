//
// Created by ingva on 2022-12-01.
//

#ifndef TDP005_GAMEOBJECT_H
#define TDP005_GAMEOBJECT_H


#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <string>

class gameobject {
public:
    gameobject(sf::Vector2f topleft)
    :topleft{topleft}{}


    sf::Vector2f  topleft;

    virtual void render(sf::RenderWindow &window) = 0;
};

class texturedobject : public gameobject {
public:
    /**
     * Create.
     */
    texturedobject(sf::Vector2f topleft,sf::Color);
    /**
     * Render the object.
     */
    void render(sf::RenderWindow &window) override;

private:
    /**
     * Shape to render.
     */
    sf::RectangleShape shape;
    sf::Color color;
};



#endif //TDP005_GAMEOBJECT_H
