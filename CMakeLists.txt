cmake_minimum_required(VERSION 3.21)
project(TDP005 LANGUAGES CXX)

include(FetchContent)
#FetchContent_Declare(SFML
#        GIT_REPOSITORY https://github.com/SFML/SFML.git
#        GIT_TAG 2.6.x)
#FetchContent_MakeAvailable(SFML)
#set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(TDP005 main.cpp states/State.h states/State.cpp states/MenuState.cpp states/GameState.cpp
        Game.cpp GameObject.h Player.cpp Player.h GameObject.cpp MovableObject.cpp MovableObject.h
        common.h enemies/Enemy.cpp enemies/Enemy.h enemies/SlowEnemy.cpp enemies/SlowEnemy.h
        states/GameOverState.cpp states/GameOverState.h TextureManager.cpp TextureManager.h
        AnimationManager.cpp AnimationManager.h Wave.cpp Wave.h Projectile.cpp Projectile.h)

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