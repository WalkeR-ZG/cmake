#include "domain/Node.h"
#include "domain/Edge.h"
#include "domain/Graph.h"
#include "domain/BestGraph.h"
#include "domain/ContextRole.h"
#include "domain/NodeMapRole.h"
#include "domain/ShortestEdgeRole.h"

void ContextRole :: formShortestEdgeBetweenTwoGraph(const Graph& graph, const BestGraph& bestGraph)
{
	for(int index = 0; index < graph.getAllNodeNum(); index++)
	{
		int lowestWeight = INVALID_VALUE;
		Edge* bestEdge   = NULL;

		if(ROLE(NodeMapRole).isNodeInBestGraph(index))
		{
			if(ROLE(ShortestEdgeRole).hasEdgeBetweenTwoGraphByIndex(index))
			{
			    if(!ROLE(NodeMapRole).isNodeInBestGraph(ROLE(ShortestEdgeRole).getShortestEdgeByIndex(index)->nodeIndex))
			    {
				    continue;
			    }
			}

			Node* node = graph.getNodeByIndex(index);
			Edge* edge = node->firstEdge;
			while(edge != NULL)
			{
				if(!ROLE(NodeMapRole).isNodeInBestGraph(edge->nodeIndex))
				{
					if(edge->weight < lowestWeight)
					{
						lowestWeight = edge->weight;
						bestEdge = edge;
					}
				}
				edge = edge->nextEdge;
			}
		}
		ROLE(ShortestEdgeRole).setShortestEdgeByIndex(index, bestEdge);
	}
}



