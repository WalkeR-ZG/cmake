#ifndef INCLUDE_DOMAIN_CELLMAP_H_
#define INCLUDE_DOMAIN_CELLMAP_H_

#include <vector>
#include <string>
#include "domain/Cell.h"

struct CellMap{
	void  initCellMap(const std::string str, int row, int column);
	Cell* first();
	bool  hasNext();
	Cell* next();
	Cell* getNeighbourCellByOffset(int rowoffset, int columnoffset);
	friend  std::ostream &operator << (std::ostream&, CellMap&);
private:
	std::vector<Cell> cellmap;
	int cellIndex;
	int _row;
	int _column;
};

#endif
