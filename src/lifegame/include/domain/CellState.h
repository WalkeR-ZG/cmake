#ifndef INCLUDE_CELLSTATE_H_
#define INCLUDE_CELLSTATE_H_

#include "infra/Role.h"
#include "infra/KeyWords.h"

struct Cell;

DEFINE_ROLE(CellState){
	ABSTRACT(CellStateType getCellStateType() const );
	ABSTRACT(bool isNeedChgState(const NeigubourState nbstate) const);
	ABSTRACT(void ChangeState(Cell* cell) const);
	static CellState* LiveCellState();
	static CellState* DeadCellState();
};

#endif
