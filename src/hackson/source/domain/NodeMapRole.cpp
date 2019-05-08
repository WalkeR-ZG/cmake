#include "domain/NodeMapRole.h"

void NodeMapRole :: setMapByIndex(const int indexInGraph, const int indexInBestGraph)
{
	indexInGraph < MAX_NODE_NUM ? nodeMap[indexInGraph] = indexInBestGraph : 0;
}

bool NodeMapRole :: isNodeInBestGraph(const int indexInGraph) const
{
	return indexInGraph < MAX_NODE_NUM ? nodeMap[indexInGraph] < MAX_NODE_NUM : false;
}

int NodeMapRole :: getNodeIndexInBestGraph(const int indexInGraph) const
{
	return indexInGraph < MAX_NODE_NUM ? nodeMap[indexInGraph] : INVALID_VALUE;
}
