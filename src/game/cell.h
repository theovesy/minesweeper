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
	Cell() :m_status(CellStatus::HIDDEN), m_proximity(0), m_mine(false) {}
	Cell(bool mine) :m_status(CellStatus::HIDDEN), m_proximity(0), m_mine(mine) {}

public:
	void set_proximity(int proximity) { m_proximity = proximity; }
	int get_proximity() const { return m_proximity; }

	void set_status(CellStatus status) { m_status = status; }
	CellStatus get_status() const { return m_status; }

	void put_mine() { m_mine = true; }
	void rm_mine() { m_mine = false; }
	bool has_mine() const { return m_mine; }

private:
	CellStatus m_status;
	int m_proximity;
	bool m_mine;
};