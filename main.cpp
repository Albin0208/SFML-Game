//
// Created by albin on 2022-12-01.
//

#include "State.h"
#include "MenuState.h"

int main()
{
    State::run(std::make_shared<MenuState>(nullptr));
    return 0;
}