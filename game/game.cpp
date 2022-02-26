#include "field.h"
#include "game.h"

Game::Game() { field = Field(0, 0, 0); }
Game::Game(int width, int height) { field = Field(width, height, 0); }
Game::Game(int width, int height, int n_mine) { field = Field(width, height, n_mine); }

void Game::open(int x, int y) { field.open_cell(x,y); }
void Game::flag(int x, int y) { field.flag_cell(x, y); }