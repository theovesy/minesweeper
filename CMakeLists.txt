cmake_minimum_required (VERSION 3.8)

project(
    Minesweeper
    VERSION 0.1
    DESCRIPTION "Minesweeper game"
)

add_executable(main src/main.cpp src/game/game.cpp src/player/player.cpp)

