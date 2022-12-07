//
// Created by albin on 2022-12-07.
//

#ifndef TDP005_ANIMATIONMANAGER_H
#define TDP005_ANIMATIONMANAGER_H

#include "common.h"

class AnimationManager {
public:
    AnimationManager();
    ~AnimationManager();

    void play(std::string const& key, sf::Sprite& sprite, bool priority = false);

    void add_animation(std::string const& key, sf::Texture* texture, sf::Vector2u image_count, float total_time);

    bool const& is_done(std::string const& key);

private:
    class Animation {
    public:
        Animation(sf::Texture* texture, sf::Vector2u image_count, float total_time)
                : texture{texture}, TOTAL_TIME{total_time}, current_frame{0}, current_time{0}, done{false} {

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

        bool const& update(sf::Sprite& sprite) {
            current_time = clock.getElapsedTime().asSeconds();
            done = false;
            if (current_time >= TOTAL_TIME) {
                current_time -= TOTAL_TIME;
                clock.restart();
                if (++current_frame >= frames.size()) {
                    current_frame = 0;
                    done = true;
                }
            }

            sprite.setTexture(*texture, true);
            sprite.setTextureRect(frames[current_frame]);

            return done;
        }

        void reset() {
            current_frame = 0;
        }

        sf::Texture* texture;
        std::vector<sf::IntRect> frames;

        int current_frame;
        float current_time;
        bool done;

        sf::Clock clock;

        float TOTAL_TIME;
    };

    std::map<std::string, Animation*> animations;
    Animation* last_animation;
    Animation* priority_animation;
};


#endif //TDP005_ANIMATIONMANAGER_H
