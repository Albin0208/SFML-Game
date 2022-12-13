//
// Created by albin on 2022-12-07.
//

#ifndef TDP005_ANIMATION_MANAGER_H
#define TDP005_ANIMATION_MANAGER_H

#include "common.h"

/**
 * Handle all the animations connected to a object
 */
class Animation_Manager {
public:
    Animation_Manager();
    ~Animation_Manager();

    /**
     * Play the animation
     * @param key - The key of the animation
     * @param sprite To what sprite it should be applied to
     * @param priority If it is a priority animation
     */
    void play(std::string const& key, sf::Sprite& sprite, bool priority = false);

    /**
     * Add a new animation to the manager
     * @param key The key to identify the animation by
     * @param texture The texture to use
     * @param image_count How many images the texture contains
     * @param total_time How long the animation should take
     */
    void add_animation(std::string const& key, sf::Texture* texture, int image_count, float total_time);

    /**
     * Get if a animation is done
     * @param key The Name of the animation
     * @return If the animation is done playing
     */
    bool const& is_done(std::string const& key);

    /**
     * Kill the animation
     */
    void kill();

    /**
     * Force a animation to play no mather what
     * @param key The animation key
     * @param sprite The sprite to apply it to
     */
    void force_play(std::string const& key, sf::Sprite& sprite);

private:
    /**
     * Handles an animation
     */
    class Animation {
    public:
        /**
         * Create a new animation
         * @param texture The texture to use
         * @param image_count How many images the texture contains
         * @param total_time How long the animation should play for
         */
        Animation(sf::Texture* texture, int image_count, float total_time)
                : texture{texture}, TOTAL_TIME{total_time}, current_frame{0}, current_time{0}, done{false} {

            sf::Vector2u sprite_size;

            sprite_size.x = texture->getSize().x / image_count;
            sprite_size.y = texture->getSize().y;

            for (int i = 0; i < image_count; ++i) {
                frames.emplace_back(
                        static_cast<int>(sprite_size.x * i),
                        static_cast<int>(0),
                        static_cast<int>(sprite_size.x),
                        static_cast<int>(sprite_size.y));
            }
        }

        ~Animation() = default;

        /**
         * Update the animation
         * @param sprite The sprite to apply it to
         * @return Returns if the animation is done
         */
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

        /**
         * Reset the animation to the beginning
         */
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


#endif //TDP005_ANIMATION_MANAGER_H
