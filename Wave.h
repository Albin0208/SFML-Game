//
// Created by albin on 2022-12-07.
//

#ifndef TDP005_WAVE_H
#define TDP005_WAVE_H


#include "common.h"
class GameObject;

class Wave {
public:
    bool is_over() const;

    void create(sf::Vector2f const& player_pos);

    vector<shared_ptr<GameObject>>& get_enemies();

    void enemy_killed();
private:
    int enemy_count{0};
    int wave_number{1};
    vector<shared_ptr<GameObject>> enemies;
};


#endif //TDP005_WAVE_H
