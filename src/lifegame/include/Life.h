#ifndef INCLUDE_LIFE_H_
#define INCLUDE_LIFE_H_

#include "infra/Role.h"
#include "domain/CellMap.h"
#include "trans/NeighbourStateTrans.h"
#include "trans/CellTrans.h"

struct Life : CellMap
			, NeighbourStateTrans
			, CellTrans
{
private:
	IMPL_ROLE(CellMap);
	IMPL_ROLE(NeighbourStateTrans);
};

#endif
