cmake_minimum_required(VERSION 3.21)
project(TDP005 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(TDP005 main.cpp states/State.h states/State.cpp states/Menu_State.cpp states/Game_State.cpp
        Game.cpp entities/Game_Object.h entities/Player.cpp entities/Player.h entities/Game_Object.cpp entities/Movable_Object.cpp entities/Movable_Object.h
        utility/common.h entities/enemies/Enemy.cpp entities/enemies/Enemy.h entities/enemies/Slow_Enemy.cpp entities/enemies/Slow_Enemy.h
        states/Game_Over_State.cpp states/Game_Over_State.h utility/Texture_Manager.cpp utility/Texture_Manager.h
        utility/Animation_Manager.cpp utility/Animation_Manager.h Wave.cpp Wave.h entities/Projectile.cpp entities/Projectile.h
        entities/enemies/Ranged_Enemy.h entities/enemies/Ranged_Enemy.h entities/enemies/Ranged_Enemy.cpp entities/enemies/Ranged_Enemy.cpp
        entities/Obstacle.cpp entities/Obstacle.h utility/Random.cpp utility/Random.h)

target_link_libraries(
        TDP005
        sfml-graphics
#        sfml-window
#        sfml-system
)

#target_link_libraries(TDP005 PRIVATE sfml-graphics sfml-window sfml-system)
#target_compile_features(TDP005 PRIVATE cxx_std_17)
#if (WIN32 AND BUILD_SHARED_LIBS)
#    add_custom_command(TARGET TDP005 POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:TDP005> $<TARGET_FILE_DIR:TDP005> COMMAND_EXPAND_LISTS)
#endif()
#
#install(TARGETS TDP005)

#cmake_minimum_required(VERSION 3.23)
#project(TDP005)
#
#set(CMAKE_CXX_STANDARD 17)
#
#set(SFML_INCLUDE_DIR "~/Libraries/SFML-2.5.1/include")
#set(SFML_LIBRARY_DIR "~/Libraries/SFML-2.5.1/lib")
#set(SFML_DIR "~/Libraries/SFML-2.5.1/lib/cmake/SFML")
#
#link_directories(SFML_LIBRARY_DIR)
#include_directories(SFML_INCLUDE_DIR)
#
#find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
#
#if(SFML_FOUND)
#    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
#    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
#    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
#endif()
#
#add_executable(TDP005 main.cpp)
#target_link_libraries (TDP005 sfml-graphics sfml-window sfml-system)