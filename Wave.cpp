//
// Created by albin on 2022-12-07.
//

#include "Wave.h"
#include "Random.h"
#include "enemies/Slow_Enemy.h"
#include "enemies/Ranged_Enemy.h"

bool Wave::is_over() const {
    return enemy_count == 0;
}

vector<shared_ptr<Game_Object>>& Wave::create(sf::Vector2f const& player_pos) {
    ++wave_number;
    enemies.reserve(wave_number);

    for(int i{0}; i < wave_number + 1; ++i){
        sf::Vector2f pos {static_cast<float>(random_int(-100, WIDTH)),
                          static_cast<float>(random_int(-100, HEIGHT))};

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
