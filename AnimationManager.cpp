//
// Created by albin on 2022-12-07.
//

#include "AnimationManager.h"

AnimationManager::~AnimationManager() {
    for (auto& a : animations)
        delete a.second;
}

void AnimationManager::play(std::string const& key, sf::Sprite& sprite) {
    animations[key]->update(sprite);
}

void AnimationManager::add_animation(std::string const& key, sf::Texture* texture, sf::Vector2u image_count, float total_time) {
    animations[key] = new Animation{texture, image_count, total_time};
}
