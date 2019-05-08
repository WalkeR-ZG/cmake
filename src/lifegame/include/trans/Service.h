#ifndef SERVICE_H_
#define SERVICE_H_

#include "infra/Role.h"
#include <string>

struct CellMap;

DEFINE_ROLE(Service){
	std::string LifeCellStateConvertToString(const char *s) const;
	void InitLifeCell(const char* intFilePath, const int row, const int column) const;
private:
	std::string GetString(const char *s) const;
	USE_ROLE(CellMap);
};

#endif
