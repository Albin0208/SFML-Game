//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_MENUSTATE_H
#define TDP005_MENUSTATE_H


#include <functional>
#include "State.h"

class MenuState : public State {
public:
    explicit MenuState(std::shared_ptr<State> resume);

    void on_key_press(sf::Keyboard::Key key) override;

    std::shared_ptr<State> update(sf::Time const& time) override;
    void render(sf::RenderWindow &target) override;
private:
    sf::Font font; // The menu text font;
    bool enter_pressed; // Is enter pressed aka a menu option has been chosen
    sf::RectangleShape background;

    // The number for the selected menu options
    int selected;

    struct Option {
        sf::Text text;

        bool not_selected;

        std::function<std::shared_ptr<State>()> action;
    };

    std::vector<Option> options;
};


#endif //TDP005_MENUSTATE_H
