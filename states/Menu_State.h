//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_MENU_STATE_H
#define TDP005_MENU_STATE_H


#include <functional>
#include "State.h"

class Menu_State : public State {
public:
    /**
     * Create a menu
     *
     * @param resume The state to resume to
     */
    explicit Menu_State(std::shared_ptr<State> const& resume);

    /**
     * Handle a keypress
     *
     * @param key The key pressed
     */
    void on_key_press(sf::Keyboard::Key key) override;

    /**
     * Update the menu
     *
     * @param time Time since last update
     * @return A pointer to a state
     */
    std::shared_ptr<State> update(sf::Time const& time, sf::RenderWindow&) override;

    /**
     * Render the menu
     *
     * @param target The target of the render
     */
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


#endif //TDP005_Menu_State_H
