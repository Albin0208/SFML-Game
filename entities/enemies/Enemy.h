//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_ENEMY_H
#define TDP005_ENEMY_H

#include "../Movable_Object.h"

class Enemy : public Movable_Object {
public:
    Enemy(sf::Vector2f const& position, float speed, sf::Vector2f const& player_pos,
          int points, int health, int damage, float single_sprite_width);
    ~Enemy() override = default;

    void update(sf::Time const& time, Game& game) override;
    void render(sf::RenderWindow& window) override;

    int attack() override = 0;

protected:
    void set_animations() override = 0;

    sf::Vector2f const& player_pos;
    int points;
    int damage;

private:
    sf::RectangleShape health_bar_background;
    sf::RectangleShape health_bar;

    int max_health;
};


#endif //TDP005_ENEMY_H
