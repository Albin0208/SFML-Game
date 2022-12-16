cmake_minimum_required(VERSION 3.21)
project(TDP005 LANGUAGES CXX)

set(SFML_MODULES sfml-network sfml-graphics sfml-system sfml-audio sfml-window)
find_package(SFML 2 COMPONENTS ${SFML_MODULES})


add_executable(TDP005 main.cpp states/State.h states/State.cpp states/Menu_State.cpp states/Game_State.cpp
        Game.cpp entities/Game_Object.h entities/Player.cpp entities/Player.h entities/Game_Object.cpp entities/Movable_Object.cpp entities/Movable_Object.h
        utility/common.h entities/enemies/Enemy.cpp entities/enemies/Enemy.h entities/enemies/Slow_Enemy.cpp entities/enemies/Slow_Enemy.h
        states/Game_Over_State.cpp states/Game_Over_State.h utility/Texture_Manager.cpp utility/Texture_Manager.h
        utility/Animation_Manager.cpp utility/Animation_Manager.h Wave.cpp Wave.h entities/Projectile.cpp entities/Projectile.h
        entities/enemies/Ranged_Enemy.h entities/enemies/Ranged_Enemy.h entities/enemies/Ranged_Enemy.cpp entities/enemies/Ranged_Enemy.cpp
        entities/Obstacle.cpp entities/Obstacle.h utility/Random.cpp utility/Random.h)

target_link_libraries (TDP005 ${SFML_MODULES})