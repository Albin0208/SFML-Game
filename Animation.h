//
// Created by albin on 2022-12-06.
//

#ifndef TDP005_ANIMATION_H
#define TDP005_ANIMATION_H

#include "common.h"

class Animation {
public:
    Animation() = default;
    Animation(sf::Texture* texture, sf::Vector2u image_count, float total_time);
    ~Animation() = default;

    bool update(int row, float dt, bool face_right, sf::Sprite& sprite);


private:
    sf::Texture* texture;
    std::vector<sf::IntRect> frames;

    int current_frame;
    float current_time;

    sf::Clock clock;

    float TOTAL_TIME;
};


#endif //TDP005_ANIMATION_H
