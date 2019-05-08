#ifndef INCLUDE_DOMAIN_CELLTRANS_H_
#define INCLUDE_DOMAIN_CELLTRANS_H_

#include "infra/Role.h"

struct CellMap;
struct NeighbourStateTrans;

DEFINE_ROLE(CellTrans){
	bool oneRoundCellChange() const;
	void changeCompelete() const;

private:
	bool doCellChange() const;
	USE_ROLE(CellMap);
	USE_ROLE(NeighbourStateTrans);
};

#endif
