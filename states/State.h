//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_STATE_H
#define TDP005_STATE_H


#include <memory>

#include "../common.h"
#include "SFML/System.hpp"

class State : public std::enable_shared_from_this<State> {
public:
    State() = default;
    virtual ~State() = default;

    /**
     * Functionality for what happens on key_press
     */
    virtual void on_key_press(sf::Keyboard::Key);
    /**
     * Functionality for what happens on key_release
     */
    virtual void on_key_release(sf::Keyboard::Key);

    /**
     * Handle the update of the state
     *
     * @param time The time passed between updates
     * @param window A reference to the window
     * @return A pointer to a state if the state should be changed
     */
    virtual std::shared_ptr<State> update(sf::Time const& time, sf::RenderWindow const& window) = 0;

    /**
     * Render the state
     *
     * @param target The render target
     */
    virtual void render(sf::RenderWindow& target) = 0;

    /**
     * Run a state
     *
     * @param state What state to run
     */
    static void run(std::shared_ptr<State> state);
};

class ExitState : public State {
public:
    /**
     * Update the exit state
     * @return A null pointer meaning the program should end
     */
    std::shared_ptr<State> update(sf::Time const&, sf::RenderWindow const&) override { return nullptr; }
    /**
     * Render the exit state
     */
    void render(sf::RenderWindow&) override {}
};

#endif //TDP005_STATE_H
