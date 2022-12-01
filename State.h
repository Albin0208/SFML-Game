//
// Created by albin on 2022-12-01.
//

#ifndef TDP005_STATE_H
#define TDP005_STATE_H


#include <memory>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class State : public std::enable_shared_from_this<State> {
public:
    State();
    virtual ~State();

    virtual void on_key_press(sf::Keyboard::Key);
    virtual void on_key_release(sf::Keyboard::Key);

    virtual std::shared_ptr<State> update(sf::Time const& time) = 0;
    virtual void render(sf::RenderWindow& target) = 0;

    static void run(std::shared_ptr<State> state);
};


#endif //TDP005_STATE_H
