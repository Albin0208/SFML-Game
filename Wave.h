//
// Created by albin on 2022-12-07.
//

#ifndef TDP005_WAVE_H
#define TDP005_WAVE_H


#include "common.h"
class GameObject;

class Wave {
public:
    /**
     * Check if the wave is over
     * @return If the wave is over
     */
    bool is_over() const;

    /**
     * Create a new wave
     * @param player_pos The position of the player
     * @return A vector of all the enemies
     */
    vector<shared_ptr<GameObject>>& create(sf::Vector2f const& player_pos);

    /**
     * Kill a enemy in the wave;
     */
    void enemy_killed();
private:
    int enemy_count{0};
    int wave_number{1};
    vector<shared_ptr<GameObject>> enemies;
};


#endif //TDP005_WAVE_H
