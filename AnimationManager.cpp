//
// Created by albin on 2022-12-07.
//

#include "AnimationManager.h"

AnimationManager::AnimationManager() : last_animation{nullptr}, priority_animation{nullptr} {}


AnimationManager::~AnimationManager() {
    for (auto& a : animations)
        delete a.second;
}

void AnimationManager::play(std::string const& key, sf::Sprite& sprite) {
    if (last_animation != animations[key]) {
        if (last_animation == nullptr)
            last_animation = animations[key];
        else {
            last_animation->reset();
            last_animation = animations[key];
        }
    }

    animations[key]->update(sprite);
}

void AnimationManager::add_animation(std::string const& key, sf::Texture* texture, sf::Vector2u image_count, float total_time) {
    animations[key] = new Animation{texture, image_count, total_time};
}