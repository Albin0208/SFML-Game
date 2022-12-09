//
// Created by albin on 2022-12-07.
//

#include <random>
#include <iostream>

#include "Wave.h"
#include "enemies/Slow_Enemy.h"
#include "enemies/Ranged_Enemy.h"

bool Wave::is_over() const {
    return enemy_count == 0;
}

vector<shared_ptr<Game_Object>>& Wave::create(sf::Vector2f const& player_pos) {
    wave_number++;
    enemies.reserve(wave_number);

//    std::random_device rd;     // Only used once to initialise (seed) engine
//    std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
//    std::uniform_int_distribution<int> wiRandom(-100,WIDTH); // Guaranteed unbiased
//    std::uniform_int_distribution<int> HeRandom(-100,HEIGHT);


    for(int i=0; i < wave_number + 1; ++i){
//        Wave::random();
        sf::Vector2f pos {static_cast<float>(Wave::random({-100, WIDTH})),
                          static_cast<float>(Wave::random({-100, HEIGHT}))};

        if (static_cast<int>(pos.x) % 2 == 0)
            enemies.emplace_back(std::make_shared<Ranged_Enemy>(pos, 75.f, player_pos));
        else
            enemies.emplace_back(std::make_shared<Slow_Enemy>(pos, 75.f, player_pos));
        ++enemy_count;
    }

    return enemies;
}

int Wave::random(sf::Vector2i range) {
    std::random_device rd;     // Only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> wiRandom(range.x,range.y); // Guaranteed unbiased

    return wiRandom(rng);

}

void Wave::enemy_killed() {
    --enemy_count;
}

int Wave::get_wave() const {
    return wave_number;
}
