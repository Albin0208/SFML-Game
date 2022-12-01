#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    game game;
    game.addobject(std::make_shared<texturedobject>(sf::Vector2f{0.0f, 0.0f}));
    game.addobject(std::make_shared<texturedobject>(sf::Vector2f{50.0f, 50.0f}));

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        game.render(window);
        //window.draw(shape);
        window.display();
    }

    return 0;
}