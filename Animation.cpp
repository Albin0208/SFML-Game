//
// Created by albin on 2022-12-06.
//

#include <iostream>
#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u image_count, float duration)
    : image_count{image_count}, duration{duration}, switch_time{duration / image_count.x}, total_time{0.0f}, played{0} {
    current_image.x = 0;

    uv_rect.width = int(texture->getSize().x / image_count.x);
    uv_rect.height = int(texture->getSize().y / image_count.y);
}

void Animation::update(int row, float dt, bool face_right) {
    current_image.y = row;
    total_time += dt;

    // TODO Take in to account cycles 


    if (total_time >= switch_time) {
        total_time -= switch_time;
        current_image.x++;
        played += switch_time;
        if (current_image.x >= image_count.x) {
            current_image.x = 0;
            running = false;
        }
    }

    uv_rect.top = int(current_image.y * uv_rect.height);

    if (face_right) {
        uv_rect.left = int(current_image.x * uv_rect.width);
        uv_rect.width = abs(uv_rect.width);
    }
    else {
        uv_rect.left = (current_image.x + 1) * abs(uv_rect.width);
        uv_rect.width = -abs(uv_rect.width);
    }
}

bool Animation::is_running() {
    return played <= duration && running;
}

void Animation::run() {
    running = true;
}
