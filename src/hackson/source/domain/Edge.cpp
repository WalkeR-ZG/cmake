#include "domain/Edge.h"

Edge::Edge(int nodeIndex, int weight, Edge *nextEdge)
              : nodeIndex(nodeIndex)
			  , weight(weight)
			  , nextEdge(nextEdge)
{
}

