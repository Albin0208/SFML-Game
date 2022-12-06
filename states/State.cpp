//
// Created by albin on 2022-12-01.
//

#include "State.h"

void State::on_key_press(sf::Keyboard::Key) {}

void State::on_key_release(sf::Keyboard::Key) {}

void State::run(std::shared_ptr<State> state) {
    sf::Clock clock{};

    sf::RenderWindow window{sf::VideoMode{WIDTH, HEIGHT}, GAME_NAME};
    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);


    while (state) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                // Close the window
                case sf::Event::Closed:
                    return;
                case sf::Event::KeyPressed:
                    state->on_key_press(event.key.code);
                    break;
                case sf::Event::KeyReleased:
                    state->on_key_release(event.key.code);
                    break;
                default:
                    break;
            }
        }
        window.clear();
        if (auto new_state = state->update(clock.restart(), window)) {
            if (std::dynamic_pointer_cast<ExitState>(new_state)) {
                return;
            } else {
                state = new_state;
            }
            continue;
        }

        state->render(window);
        window.display();

    }
}