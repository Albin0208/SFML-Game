#include "gameobject.h"



texturedobject::texturedobject(sf::Vector2f topleft,sf::Color)
        : gameobject(topleft) {



    shape.setSize(sf::Vector2f(50.0f, 50.0f));
    shape.setFillColor(sf::Color::Blue);
    //shape.setOrigin(size.x / 2, size.y / 2);
}

void texturedobject::render(sf::RenderWindow &window) {
    shape.setPosition(topleft);
    window.draw(shape);
}
