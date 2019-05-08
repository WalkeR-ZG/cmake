#include "domain/CellState.h"
#include "domain/Cell.h"

#define DEFINE_CELLSTRATEGY_SUBCLASS(classname)                            \
	struct classname : CellState{                                          \
		OVERRIDE(CellStateType getCellStateType() const );                 \
		OVERRIDE(bool isNeedChgState(const NeigubourState nbstate) const); \
		OVERRIDE(void ChangeState(Cell* cell) const);                      \
}

DEFINE_CELLSTRATEGY_SUBCLASS(Live);
DEFINE_CELLSTRATEGY_SUBCLASS(Dead);

CellStateType Live::getCellStateType() const
{
	return SURVIVE;
}

CellStateType Dead::getCellStateType() const
{
	return DEATH;
}

bool Live::isNeedChgState(const NeigubourState nbstate) const
{
	return (nbstate < 2 || nbstate > 3);
}

bool Dead::isNeedChgState(const NeigubourState nbstate) const
{
	return 3 == nbstate;
}

void Live::ChangeState(Cell* cell) const
{
	cell->setCellState(CellState::DeadCellState());
}

void Dead::ChangeState(Cell* cell)const
{
	cell->setCellState(CellState::LiveCellState());
}

CellState* CellState::LiveCellState()
{
    static Live live;
    return &live;
}

CellState* CellState::DeadCellState()
{
    static Dead dead;
    return &dead;
}
