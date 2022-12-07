//
// Created by albin on 2022-12-06.
//

#include <iostream>
#include "Animation.h"
#include "TextureManager.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u image_count, float total_time)
    : texture{texture}, TOTAL_TIME{total_time}, current_frame{0}, current_time{0} {

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
}

bool Animation::update(int row, float dt, bool face_right, sf::Sprite& sprite) {
    current_time = clock.getElapsedTime().asSeconds();

    if (current_time >= TOTAL_TIME) {
        current_time -= TOTAL_TIME;
        clock.restart();
        if (++current_frame >= frames.size())
            current_frame = 0;
    }

    sprite.setTexture(*texture, true);
    sprite.setTextureRect(frames[current_frame]);

    return false;
}