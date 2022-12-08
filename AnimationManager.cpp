//
// Created by albin on 2022-12-07.
//

#include "AnimationManager.h"

AnimationManager::AnimationManager() : last_animation{nullptr}, priority_animation{nullptr} {}


AnimationManager::~AnimationManager() {
    for (auto& a : animations)
        delete a.second;
}

void AnimationManager::play(std::string const& key, sf::Sprite& sprite, bool priority) {
    if (priority_animation == animations[key]) {
        animations[key]->update(sprite);
    } else {
        if (priority)
            priority_animation = animations[key];

        if (last_animation != animations[key]) {
            if (last_animation == nullptr)
                last_animation = animations[key];
            else {
                last_animation->reset();
                last_animation = animations[key];
            }
        }

        if (animations[key]->update(sprite)) {
            priority_animation = nullptr;
        }
    }
}

void AnimationManager::add_animation(std::string const& key, sf::Texture* texture, sf::Vector2u image_count, float total_time) {
    animations[key] = new Animation{texture, image_count, total_time};
}

bool const& AnimationManager::is_done(std::string const& key) {
    return animations[key]->done;
}

void AnimationManager::kill() {
    priority_animation = nullptr;
    last_animation = nullptr;
}
