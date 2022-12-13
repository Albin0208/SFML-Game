//
// Created by albda746 on 2022-12-13.
//

#include <random>
#include "Random.h"

/**
 * Random number generator.
 */
class Generator {
public:
    Generator() {
        std::random_device rd;
        std::mt19937 rn(rd());
        rng = rn;
    }

    std::mt19937 rng;
};

static Generator generator;

/**
 * Generate a random int in a interval
 * @param min Start of the interval
 * @param max End of the interval
 * @return The generated int
 */
int random_int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator.rng);
}

