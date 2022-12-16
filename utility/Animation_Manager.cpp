//
// Created by albin on 2022-12-07.
//

#include "Animation_Manager.h"

Animation_Manager::Animation_Manager() : last_animation{nullptr}, priority_animation{nullptr} {}


Animation_Manager::~Animation_Manager() {
    for (auto& a : animations)
        delete a.second;
}

void Animation_Manager::play(std::string const& key, sf::Sprite& sprite, bool priority) {
    if (priority_animation == animations[key]) {
        animations[key]->update(sprite);
    } else {
        if (priority)
            priority_animation = animations[key];

        if (last_animation != animations[key]) {
            if (last_animation == nullptr)
                last_animation = animations[key];
            else {
                // Reset the previous animation to the beginning
                last_animation->reset();
                last_animation = animations[key];
            }
        }

        if (animations[key]->update(sprite)) {
            priority_animation = nullptr;
        }
    }
}

void Animation_Manager::add_animation(std::string const& key, sf::Texture* texture, int image_count, float total_time) {
    animations[key] = new Animation{texture, image_count, total_time};
}

bool const& Animation_Manager::is_done(std::string const& key) {
    return animations[key]->done;
}

void Animation_Manager::force_play(std::string const& key, sf::Sprite& sprite) {
    priority_animation = animations[key];
    play(key, sprite);
}
