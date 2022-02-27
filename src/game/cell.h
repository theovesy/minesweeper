#pragma once 

enum class CellStatus
{
	HIDDEN,
	FLAGGED,
	OPEN, // and not mined 
	MINE
};

struct Output_Cell
{
	int prox;
	CellStatus status;
};

class Cell
{
public:
	Cell() :m_mine(0), m_proximity(0), m_status(CellStatus::HIDDEN) {}

	Cell(bool mine) :m_mine(mine), m_proximity(0), m_status(CellStatus::HIDDEN) {}

public:
	void set_proximity(int proximity) { m_proximity = proximity; }
	int get_proximity() { return m_proximity; }

	void set_status(CellStatus status) { m_status = status; }
	CellStatus get_status() { return m_status; }

	void put_mine() { m_mine = true; }
	void rm_mine() { m_mine = false; }
	bool has_mine() { return m_mine; }

private:
	CellStatus m_status;
	int m_proximity;
	bool m_mine;
};