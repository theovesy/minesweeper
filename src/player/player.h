#pragma once
#include "../game/game.h"
#include <string>
#include <iostream>
#include <vector>

enum class InputType
{
    OPEN,
    FLAG,
    INVALID
};

struct Input
{
    InputType type; 
    int x;
    int y;
};

class Player
{
public:
    Player();
    Player(int width, int height, int n_mine);

public:
    void play();

private:
    void print_field();
    void print_win();
    void print_defeat();

    Input parse_input(const std::string& input);
    void process_input();
    int find_space_after(int a, const std::string& input_str);
    
private:
    Game game;
    int m_width, m_height;
    bool game_over;
};