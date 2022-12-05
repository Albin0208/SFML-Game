//
// Created by albin on 2022-12-05.
//

#include <iostream>
#include <sstream>
#include "GameOverState.h"
#include "GameState.h"

GameOverState::GameOverState(Game const& game) : selected{0}, enter_pressed{false} {
    font.loadFromFile("../resources/fonts/font.ttf");

    options.push_back(
            {sf::Text{"New Game", font, 60}, false,
             [](){return std::make_shared<GameState>();}});
    options.push_back({sf::Text{"Exit", font, 60}, false,
                       [](){return std::make_shared<ExitState>();}});

}

void GameOverState::on_key_press(sf::Keyboard::Key key) {
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
    }
}

std::shared_ptr<State> GameOverState::update(sf::Time const& time, sf::RenderWindow const&) {
    for (size_t i = 0; i < options.size(); i++) {
        Option& o = options[i];

        if (i == selected) {
            o.not_selected = false;
        } else {
            o.not_selected = true;
        }
    }


    if (enter_pressed)
        return options[selected].action();
    return nullptr;
}


void GameOverState::render(sf::RenderWindow& target) {
    float y{100};
    auto windowSize = target.getSize();

    sf::Text t{"Game Over", font, 80};
    t.setPosition((windowSize.x - t.getLocalBounds().width) / 2, y);
    t.setFillColor(sf::Color(255, 0, 0));
    target.draw(t);
    y += t.getLocalBounds().height * 2.5f;

    // TODO: Display score and waves survived
    std::stringstream ss{};
    ss << "Points: ";
    ss << 100;
    t.setString(ss.str());
    t.setCharacterSize(40);
    t.setPosition((windowSize.x - t.getLocalBounds().width) / 2, y);
    t.setFillColor(sf::Color::White);
    target.draw(t);
    y += t.getLocalBounds().height * 3.0f;

    for (auto& o : options) {
        auto bounds = o.text.getLocalBounds();
        o.text.setPosition((windowSize.x - bounds.width) / 2, y);
        y += bounds.height * 2.0f;

        int state = static_cast<int>(255 * o.not_selected);
        o.text.setFillColor(sf::Color(state, 255, state));
        target.draw(o.text);
    }
}