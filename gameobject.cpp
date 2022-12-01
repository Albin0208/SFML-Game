#include "gameobject.h"



texturedobject::texturedobject(sf::Vector2f topleft)
        : gameobject(topleft){


    texture.loadFromFile("..//textures//player.png");
    //sprite.setSize(sf::Vector2f(50.0f, 50.0f));
    sprite.setTexture(texture);
    //sprite.setTextureRect(sf::IntRect(16, 16, 16, 16));
    //sprite.setColor(sf::Color(255, 255, 255, 200));

    //shape.setOrigin(size.x / 2, size.y / 2);
}

void texturedobject::render(sf::RenderWindow &window) {
    sprite.setPosition(topleft);
    window.draw(sprite);
}
