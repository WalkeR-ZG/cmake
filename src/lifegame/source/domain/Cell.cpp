#include "domain/Cell.h"
#include "domain/CellState.h"

Cell::Cell(CellState* cellstate):_cellstate(cellstate),_nbstate(0)
{
}

void Cell::setCellState(CellState* cellstate)
{
	this->_cellstate = cellstate;
}

bool Cell::isCellSurvive() const
{
	return SURVIVE == _cellstate->getCellStateType();
}

void Cell:: setNeigubourState(const NeigubourState nbstate)
{
	_nbstate = nbstate;
}

CellState* Cell::getCellState() const
{
	return _cellstate;
}

NeigubourState Cell::getNeigubourState() const
{
	return _nbstate;
}
