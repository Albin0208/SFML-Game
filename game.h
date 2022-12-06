#ifndef TDP005_GAME_H
#define TDP005_GAME_H


#include "gameobject.h"
#include <memory>

class game{
public:
    void addobject(std::shared_ptr<gameobject> object);    //lägger till object i spelet

    void render(sf::RenderWindow &to);    //renderar alla object i spelet

private:
    std::vector<std::shared_ptr<gameobject>> objects; //vector med pekare på alla objekt i spelet

};


#endif //TDP005_GAME_H
