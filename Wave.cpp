//
// Created by albin on 2022-12-07.
//

#include "Wave.h"
#include "utility/Random.h"
#include "entities/enemies/Ranged_Enemy.h"
#include "entities/enemies/Slow_Enemy.h"

bool Wave::is_over() const {
    return enemy_count == 0;
}

vector<shared_ptr<Game_Object>>& Wave::create(sf::Vector2f const& player_pos) {
    ++wave_number;
    enemies.reserve(wave_number);

    for(int i{0}; i < wave_number + 1; ++i){
        int spawning_position = random_int(1,4); //if to spawn above,below,left or right of screen
        sf::Vector2f pos{0,0};
        if(spawning_position==1) {          //Above Screen
            pos = {static_cast<float>(random_int(-100, WIDTH)),
                   static_cast<float>(random_int(-100, 0))};
        }
            else if(spawning_position==2) {      //Below Screen
            pos = {static_cast<float>(random_int(-100, WIDTH)),
                   static_cast<float>(random_int(HEIGHT, HEIGHT + 100))};
            }
            else if(spawning_position==3){      //Left of Screen
                pos = {static_cast<float>(random_int(-100, 0)),
                       static_cast<float>(random_int(-100, HEIGHT))};
            }
            else{                               //Right of Screen
                pos = {static_cast<float>(random_int(WIDTH, WIDTH+100)),
                       static_cast<float>(random_int(-100, HEIGHT))};
            }


        //sf::Vector2f pos {static_cast<float>(random_int(-100, WIDTH)),
        //                  static_cast<float>(random_int(-100, HEIGHT))};

        if (static_cast<int>(pos.x) % 2 == 0)
            enemies.emplace_back(std::make_shared<Ranged_Enemy>(pos, 75.f, player_pos));
        else
            enemies.emplace_back(std::make_shared<Slow_Enemy>(pos, 75.f, player_pos));
        ++enemy_count;
    }

    return enemies;
}

void Wave::enemy_killed() {
    --enemy_count;
}

int Wave::get_wave() const {
    return wave_number;
}
