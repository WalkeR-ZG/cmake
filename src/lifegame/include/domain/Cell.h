#ifndef INCLUDE_DOMAIN_CELL_H_
#define INCLUDE_DOMAIN_CELL_H_

#include "infra/KeyWords.h"

struct CellState;

struct Cell{
	void setCellState(CellState* cellstate);
	void setNeigubourState(const NeigubourState nbstate);
	bool isCellSurvive() const;
	Cell(CellState* cellstate);
	CellState* getCellState() const;
	NeigubourState getNeigubourState() const;

private:
	CellState* _cellstate;
	NeigubourState _nbstate;
};

#endif
