//
// Created by albin on 2022-12-07.
//

#ifndef TDP005_WAVE_H
#define TDP005_WAVE_H


#include "utility/common.h"
class Game_Object;

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
    vector<shared_ptr<Game_Object>>& create(sf::Vector2f const& player_pos);

    /**
     * Kill a enemy in the wave;
     */
    void enemy_killed();

    int get_wave() const;

private:
    int enemy_count{0};
    int wave_number{0};
    vector<shared_ptr<Game_Object>> enemies;
};


#endif //TDP005_WAVE_H
