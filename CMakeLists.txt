cmake_minimum_required (VERSION 3.8)

project(
    Minesweeper
    VERSION 0.1
    DESCRIPTION "Minesweeper game"
)

add_executable(${PROJECT_NAME} src/main.cpp src/player/player.cpp)

add_subdirectory(src/game)

target_link_libraries(${PROJECT_NAME} minesweeper_game)