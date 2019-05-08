#include "domain/CellMap.h"
#include "domain/Cell.h"
#include "domain/CellState.h"
#include <fstream>

using namespace std;

void CellMap::initCellMap(const string str, const int row, const int column)
{
	_row = row;
	_column = column;
	cellmap.clear();

	for(unsigned int index = 0; index < str.size(); index++)
	{
		str[index] == '1' ? cellmap.push_back(Cell(CellState::LiveCellState())) : cellmap.push_back(Cell(CellState::DeadCellState()));
	}
}

Cell* CellMap::first()
{
	cellIndex = 0;
	return &cellmap[cellIndex];
}

bool CellMap::hasNext()
{
	return cellIndex != _row * _column;
}

Cell* CellMap::next()
{
	return &cellmap[++cellIndex];
}
#define ASSERT_OUT_RANGE(positon,total)  \
	if((positon < 0)||(positon >= total)) \
	{                                    \
		return NULL;                     \
	}

Cell* CellMap:: getNeighbourCellByOffset(int rowoffset, int columnoffset)
{
	int row = cellIndex / _column + rowoffset;
	int column = cellIndex % _column + columnoffset;

	ASSERT_OUT_RANGE(row, _row);
	ASSERT_OUT_RANGE(column, _column);
    return &cellmap[row *_column + column];
}

std::ostream &operator << (std::ostream& os, CellMap& cellmap)
{
	int cellnum = 0;
	Cell* cell = cellmap.first();
	while(cellmap.hasNext())
	{
		cell->isCellSurvive() ? os<<"$" : os<<" ";
		cellnum++;
		if((0 == cellnum%cellmap._column) && (cellmap._row != cellnum/cellmap._column))
		{
			os<<endl;
		}
		cell = cellmap.next();
	}
	return os;
}
