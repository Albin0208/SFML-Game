//
// Created by albin on 2022-12-06.
//

#include <iostream>
#include "Animation.h"
#include "TextureManager.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u image_count, float total_time)
    : texture{texture}, image_count{image_count}, TOTAL_TIME{total_time}, current_frame{0}, current_time{0} {

    sf::Vector2u sprite_size;

    sprite_size.x = texture->getSize().x / image_count.x;
    sprite_size.y = texture->getSize().y / image_count.y;

    for (int i = 0; i < image_count.x; ++i) {
        frames.emplace_back(
                    static_cast<int>(sprite_size.x * i),
                    static_cast<int>(0),
                    static_cast<int>(sprite_size.x),
                    static_cast<int>(sprite_size.y));
    }
    std::cout << frames.size() << std::endl;

//    uv_rect.width = int(texture->getSize().x / image_count.x);
//    uv_rect.height = int(texture->getSize().y / image_count.y);
}
//Animation::Animation(sf::Texture* texture, sf::Vector2u image_count, float duration)
//    : texture{texture}, image_count{image_count}, duration{duration}, switch_time{duration / image_count.x}, total_time{0.0f}, played{0} {
//    current_image.x = 0;
//
//    uv_rect.width = int(texture->getSize().x / image_count.x);
//    uv_rect.height = int(texture->getSize().y / image_count.y);
//}

void Animation::update(int row, float dt, bool face_right, sf::Sprite& sprite) {
    current_time = clock.getElapsedTime().asSeconds();

    if (current_time >= TOTAL_TIME) {
        current_time -= TOTAL_TIME;
        clock.restart();
        if (++current_frame >= frames.size())
            current_frame = 0;
    }

//    sprite.setTexture(*texture);
//    sprite.setTextureRect(frames[current_frame]);

//    if (!face_right) {
//        frames[current_frame].width = -abs(frames[current_frame].width);
//    } else {
//        frames[current_frame].width = abs(frames[current_frame].width);
//    }

    sprite.setTexture(*texture, true);
    sprite.setTextureRect(frames[current_frame]);

    //sprite.setOrigin({sprite.getScale().x /2, sprite.getScale().y /2});


//    current_image.y = row;
//    total_time += dt;
//
//    // TODO Take in to account cycles
//
//    std::cout << "Update" << std::endl;
//
//    if (total_time >= switch_time) {
//        total_time -= switch_time;
//        played += switch_time;
//        if (++current_image.x >= image_count.x) {
//            current_image.x = 0;
//            running = false;
//        }
//    }
//
//    uv_rect.top = int(current_image.y * uv_rect.height);
//
//    if (face_right) {
//        uv_rect.left = int(current_image.x * uv_rect.width);
//        uv_rect.width = abs(uv_rect.width);
//    }
//    else {
//        uv_rect.left = (current_image.x + 1) * abs(uv_rect.width);
//        uv_rect.width = -abs(uv_rect.width);
//    }
//
//    sprite.setTexture(*texture);
//    sprite.setTextureRect(uv_rect);
}

//bool Animation::is_running() {
//    return played <= duration && running;
//}
//
//void Animation::run() {
//    running = true;
//}
