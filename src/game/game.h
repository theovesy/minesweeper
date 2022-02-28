#pragma once
#include "field.h"

class Game
{
public:
	Game();
	Game(int width, int height);
	Game(int width, int height, int n_mine);

public:
	void open(int x, int y);
	void flag(int x, int y);

	std::vector<std::vector<Output_Cell>> get_field();
	bool has_mine(int x, int y) const;

	bool won();
private:
	Field field;
};