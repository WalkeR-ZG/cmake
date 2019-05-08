#ifndef INCLUDE_HACKSON_DOMAIN_NODEMAPROLE_H_
#define INCLUDE_HACKSON_DOMAIN_NODEMAPROLE_H_

#include "infra/Role.h"
#include "infra/Base.h"

DEFINE_ROLE(NodeMapRole)
{
public:
	void setMapByIndex(const int indexInGraph, const int indexInBestGraph);
	bool isNodeInBestGraph(const int indexInGraph) const;
	int  getNodeIndexInBestGraph(const int indexInGraph) const;
private:
	int nodeMap[MAX_NODE_NUM];
};

#endif
