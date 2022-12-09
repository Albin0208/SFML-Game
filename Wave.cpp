//
// Created by albin on 2022-12-07.
//

#include <random>
#include <iostream>

#include "Wave.h"
#include "enemies/Slow_Enemy.h"

bool Wave::is_over() const {
//    std::cout << enemy_count << "\n";
    return enemy_count == 0;
}

vector<shared_ptr<Game_Object>>& Wave::create(sf::Vector2f const& player_pos) {
    wave_number++;
    enemies.reserve(wave_number);

    std::random_device rd;     // Only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> wiRandom(0,WIDTH); // Guaranteed unbiased
    std::uniform_int_distribution<int> HeRandom(0,HEIGHT);


    for(int i=0; i < wave_number + 1; ++i){
        sf::Vector2f pos {static_cast<float>(wiRandom(rng)), static_cast<float>(HeRandom(rng))};
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
