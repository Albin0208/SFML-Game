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
//    Animation(sf::Texture* texture, sf::Vector2u image_count, float duration);
    ~Animation() = default;

    void update(int row, float dt, bool face_right, sf::Sprite& sprite);
//    void update(int row, float dt, bool face_right, sf::Sprite& sprite);
//
//    sf::IntRect uv_rect;
//    bool is_running();
//    void run();

private:
    sf::Vector2u image_count;
    //sf::Vector2u current_image;
    sf::Texture* texture;

//    bool running;
//
//    float duration;
//    float played;
//    float total_time;
//    float switch_time;

    std::vector<sf::IntRect> frames;


    int current_frame;
    float current_time;

    sf::Clock clock;

    float TOTAL_TIME;
};


#endif //TDP005_ANIMATION_H
