//
// Created by albin on 2022-12-01.
//

#include "states/Menu_State.h"

int main()
{
    // Run the game and display the main menu
    State::run(std::make_shared<Menu_State>(nullptr));
    return 0;
}