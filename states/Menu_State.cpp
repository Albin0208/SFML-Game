//
// Created by albin on 2022-12-01.
//

#include <iostream>
#include "Menu_State.h"
#include "Game_State.h"

Menu_State::Menu_State(std::shared_ptr<State> const& resume) : selected{0}, enter_pressed{false} {
    font.loadFromFile(FONT_PATH);
    // If the game is paused
    if (resume)
        options.push_back({sf::Text{"Resume", font, 60}, false, [resume](){return resume;}});

    options.push_back(
            {sf::Text{"New Game", font, 60}, false,
             [](){return std::make_shared<Game_State>();}});
    options.push_back({sf::Text{"Exit", font, 60}, false, [](){return std::make_shared<Exit_State>();}});

}

void Menu_State::on_key_press(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Down:
        case sf::Keyboard::S:
            if (selected + 1 < options.size())
                selected++;
            break;

        case sf::Keyboard::Up:
        case sf::Keyboard::W:
            if (selected > 0)
                selected--;
            break;

        case sf::Keyboard::Return:
            enter_pressed = true;
            break;
        default:
            break;
    }
}

std::shared_ptr<State> Menu_State::update(sf::Time const& time, sf::RenderWindow&) {
    for (size_t i = 0; i < options.size(); i++) {
        Option& o = options[i];

        o.not_selected = i != selected;
    }

    if (enter_pressed)
        return options[selected].action();
    return nullptr;
}

void Menu_State::render(sf::RenderWindow& target) {
    float y{100};
    auto windowSize = target.getSize();

    sf::Text t{GAME_NAME, font, 100};
    t.setPosition((windowSize.x - t.getLocalBounds().width) / 2, y);
    t.setFillColor(sf::Color(255, 24, 100));
    target.draw(t);
    y += t.getLocalBounds().height * 2.5f;

    for (auto& o : options) {
        auto bounds = o.text.getLocalBounds();
        o.text.setPosition((windowSize.x - bounds.width) / 2, y);
        y += bounds.height * 2.0f;

        int state = static_cast<int>(255 * o.not_selected);
        o.text.setFillColor(sf::Color(state, 255, state));
        target.draw(o.text);
    }
}
