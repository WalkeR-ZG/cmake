#include "trans/NeighbourStateTrans.h"
#include "infra/KeyWords.h"
#include "domain/Cell.h"
#include "domain/CellMap.h"
#include "domain/CellState.h"

void NeighbourStateTrans::updateNeighbourState() const
{
	int neighourmap[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},
							  {0,-1},            {0, 1},
							  {1,-1},    {1,0},  {1, 1}};
	NeigubourState nbstate;

	Cell* cell = ROLE(CellMap).first();
	while(ROLE(CellMap).hasNext())
	{
		nbstate = 0;
		for(int i = 0; i < 8; i++)
		{
			Cell* nbcell = ROLE(CellMap).getNeighbourCellByOffset(neighourmap[i][0],neighourmap[i][1]);
		    if((NULL != nbcell) &&(nbcell->isCellSurvive()))
		    {
			    nbstate++;
		    }
		}
		cell->setNeigubourState(nbstate);
		cell = ROLE(CellMap).next();
	}
}
