cmake_minimum_required (VERSION 3.8)

project(
    Minesweeper
    VERSION 0.1
    DESCRIPTION "Minesweeper game"
)

add_executable(main main.cpp game/game.cpp console/console.cpp)

