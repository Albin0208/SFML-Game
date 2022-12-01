#include "game.h"

    void game::addobject(std::shared_ptr<gameobject> object_to_add){
        objects.push_back(object_to_add);
    }

    void game::render(sf::RenderWindow &to) {
        for (auto &x : objects)
            x->render(to);
    }





