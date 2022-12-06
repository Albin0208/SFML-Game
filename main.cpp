//
// Created by albin on 2022-12-01.
//

#include "states/MenuState.h"

int main()
{
    // Run the game and display the main menu
    State::run(std::make_shared<MenuState>(nullptr));
    return 0;
}