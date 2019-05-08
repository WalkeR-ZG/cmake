#include "domain/ShortestEdgeRole.h"
#include "domain/Edge.h"

void ShortestEdgeRole :: setShortestEdgeByIndex(const int index, const Edge* edge)
{
	index < MAX_NODE_NUM ? shortestEdge[index] = const_cast<Edge*>(edge) : 0;
}

bool ShortestEdgeRole :: hasEdgeBetweenTwoGraphByIndex(const int index) const
{
	return index < MAX_NODE_NUM ? shortestEdge[index] != NULL : false;
}

Edge* ShortestEdgeRole :: getShortestEdgeByIndex(const int index) const
{
	return index < MAX_NODE_NUM ? shortestEdge[index] : NULL;
}
