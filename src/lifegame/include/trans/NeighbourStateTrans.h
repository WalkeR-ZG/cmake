#ifndef INCLUDE_DOMAIN_NEIGHBOURSTATETRANS_H_
#define INCLUDE_DOMAIN_NEIGHBOURSTATETRANS_H_

#include "infra/Role.h"
struct CellMap;

DEFINE_ROLE(NeighbourStateTrans){
	void updateNeighbourState() const;
private:
	USE_ROLE(CellMap);
};

#endif
