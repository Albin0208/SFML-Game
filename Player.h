//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_PLAYER_H
#define TDP005_PLAYER_H

#include "MovableObject.h"

class Player : public MovableObject {
public:
    Player(sf::Vector2f const& position, float speed);

    void update(sf::Time const& time, Game& game,sf::RenderWindow const& window) override;
    void render(sf::RenderWindow& window) override;
    int attack() override;

    sf::Vector2f const& get_pos();

private:
    int health;
    sf::Clock attack_timer;
    int32_t attack_speed;

};


#endif //TDP005_PLAYER_H
