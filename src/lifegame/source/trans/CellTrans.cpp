#include "trans/CellTrans.h"
#include "trans/NeighbourStateTrans.h"
#include "domain/Cell.h"
#include "domain/CellState.h"
#include "domain/CellMap.h"

bool CellTrans::doCellChange() const
{
	int changetime = 0;

	Cell* cell = ROLE(CellMap).first();
	while(ROLE(CellMap).hasNext())
	{
		if(cell->getCellState()->isNeedChgState(cell->getNeigubourState()))
		{
			changetime++;
			cell->getCellState()->ChangeState(cell);
		}
		cell = ROLE(CellMap).next();
	}
	return changetime != 0;
}

bool CellTrans::oneRoundCellChange() const
{
	ROLE(NeighbourStateTrans).updateNeighbourState();
	return doCellChange();
}

void CellTrans:: changeCompelete() const
{
	while(oneRoundCellChange())
	{}
}
