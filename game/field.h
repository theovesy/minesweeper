#pragma once

#include "Cell.h"
#include <vector>
#include <random>

class Field
{
public:
	Field() { construct(0, 0, 0); }
	Field(int width, int height) { construct(width, height, 0); }
	Field(int width, int height, int n_mine) { construct(width, height, n_mine); }

public:
	void open_cell(int x, int y)
	{
		Cell& cur_cell = m_field[x][y];
		if(cur_cell.get_status() < CellStatus::OPEN)
		{
			if (!cur_cell.has_mine())
				discover(x,y);
			else
				cur_cell.set_status(CellStatus::MINE);
		}
	}

	void flag_cell(int x, int y)
	{
		Cell& cur_cell = m_field[x][y];
		if (cur_cell.get_status() < CellStatus::FLAGGED)
			cur_cell.set_status(CellStatus::FLAGGED);
	}


private:
	void construct(int width, int height, int n_mine)
	{
		m_width = width;
		m_height = height;
		m_field = generate_cell_field(width, height);
		set_mines(n_mine);
		compute_proximity();
	}

	std::vector<std::vector<Cell>> generate_cell_field(int width, int height)
	{
		std::vector<Cell> row(height, Cell());
		std::vector<std::vector<Cell>> vect(width, row);
		return vect;
	}

	// puts mines in random spots
	void set_mines(int n_mine)
	{
		int x, y;
		for (int i = 0; i < n_mine; i++)
		{
			x = random_int(0, m_width-1);
			y = random_int(0, m_height-1);
			m_field[x][y].put_mine();
		}
	}

	int random_int(int min, int max)
	{
		// The random device
		std::random_device rd;
		// The "Mersenne Twister" random engine
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(min, max);

		return dist(gen);
	}

	//returns the number of mine around a cell
	int mine_around(int x, int y)
	{
		int count = 0;

		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i < 0 || j<0 || i >= m_width || j>=m_height)
					continue;
				else if (m_field[i][j].has_mine())
					count++;
			}
		}

		return count;
	}

	//compute the number of mines around each cell
	void compute_proximity()
	{
		for (int i = 0; i < m_width; i++)
		{
			for (int j = 0; j < m_height; j++)
			{
				m_field[i][j].set_proximity(mine_around(i, j));
			}
		}
	}

	void discover(int x, int y)
	{
		Cell& cur_cell = m_field[x][y];
		cur_cell.set_status(CellStatus::OPEN);

		if (cur_cell.get_proximity() == 0)
		{
			for (int i = x - 1; i <= x + 1; i++)
			{
				for (int j = y - 1; j <= y + 1; j++)
				{
					if (i < 0 || j<0 || i >= m_width || j>=m_height)
						continue;
					else if (m_field[i][j].get_status() < CellStatus::OPEN && !m_field[i][j].has_mine())
						discover(i,j);
				}
			}	
		}
	}

private:
	std::vector<std::vector<Cell>> m_field;
	int m_width, m_height;
};
