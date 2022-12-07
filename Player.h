//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_PLAYER_H
#define TDP005_PLAYER_H

#include "MovableObject.h"

class Player : public MovableObject {
public:
    Player(sf::Vector2f const& position, float speed);

    void update(sf::Time const& time, Game& game) override;

    int attack(sf::Time const& time) override;

    sf::Vector2f const& get_pos();

protected:
    void set_animations() override;

private:
    int health;
    std::string type;
};


#endif //TDP005_PLAYER_H
