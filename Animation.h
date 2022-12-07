//
// Created by albin on 2022-12-06.
//

#ifndef TDP005_ANIMATION_H
#define TDP005_ANIMATION_H

#include "common.h"

class Animation {
public:
    Animation(sf::Texture* texture, sf::Vector2u image_count, float duration);
    ~Animation() = default;

    void update(int row, float dt, bool face_right);

    sf::IntRect uv_rect;
    bool is_running();
    void run();

private:
    sf::Vector2u image_count;
    sf::Vector2u current_image;

    bool running;

    float duration;
    float played;
    float total_time;
    float switch_time;
};


#endif //TDP005_ANIMATION_H
