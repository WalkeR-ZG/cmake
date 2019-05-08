#include "domain/Node.h"
#include "domain/Edge.h"
#include "domain/Graph.h"
#include "domain/BestGraph.h"
#include "domain/AlgorithmRole.h"
#include "domain/ContextRole.h"
#include "domain/NodeMapRole.h"
#include "domain/ShortestEdgeRole.h"

#include <iostream>
using namespace std;

struct ContextImpl : ContextRole
                   , NodeMapRole
				   , ShortestEdgeRole
{
private:
	IMPL_ROLE(NodeMapRole);
	IMPL_ROLE(ShortestEdgeRole);
};


void BestGraph :: initBestGraph()
{
	totalWeight = 0;
	for(int index = 0; index <ROLE(Graph).getAllNodeNum(); index++)
	{
		Node* node = ROLE(Graph).getNodeByIndex(index);
		if(node->isVertex)
		{
			addNode(new Node(node->name, node->isVertex));
			context->ROLE(NodeMapRole).setMapByIndex(index, getAllNodeNum() - 1);
		}
		else
		{
			context->ROLE(NodeMapRole).setMapByIndex(index,INVALID_VALUE);
		}
	}
}

void BestGraph :: updateBestGraph(const int indexInGraph)
{
	Edge *bestEdge = context->ROLE(ShortestEdgeRole).getShortestEdgeByIndex(indexInGraph);
	Node* nodeAdd = ROLE(Graph).getNodeByIndex(bestEdge->nodeIndex);
	Node* nodeInBest = ROLE(Graph).getNodeByIndex(indexInGraph);
	addNode(new Node(nodeAdd->name, nodeAdd->isVertex));
	addEdge(nodeAdd->name, nodeInBest->name, bestEdge->weight);

	ROLE(AlgorithmRole).update(*this, nodeInBest->name);
	context->ROLE(NodeMapRole).setMapByIndex(bestEdge->nodeIndex, getAllNodeNum() - 1);
}


void BestGraph :: exec()
{
	context = new ContextImpl();
	ROLE(AlgorithmRole).init();
	initBestGraph();
	for(int i = 0; i < ROLE(Graph).getAllNodeNum(); i++)
	{
		execOneRound();
	}
	delete context;
}

int BestGraph :: getTotalWeight() const
{
	return totalWeight;
}

std::ostream &operator<< (std::ostream& os , const BestGraph& graph)
{
	for(int index = 0; index <graph.getAllNodeNum(); index++)
	{
		Node* node = graph.getNodeByIndex(index);
		Edge* edge = node->firstEdge;
		while(NULL != edge)
		{
		    if(index < edge->nodeIndex)
		    {
			    os<<node->name<<","<<graph.getNodeByIndex(edge->nodeIndex)->name \
			      <<","<<edge->weight<<endl;
		    }
		    edge = edge->nextEdge;
		}
	}
	return os;
}

void BestGraph :: execOneRound()
{
	context->formShortestEdgeBetweenTwoGraph(ROLE(Graph), *this);

	int lowestWeight = INVALID_VALUE;
	int index = INVALID_VALUE;
	for(int i = 0; i < ROLE(Graph).getAllNodeNum(); i++)
	{
		if(context->ROLE(ShortestEdgeRole).hasEdgeBetweenTwoGraphByIndex(i))
		{
			Edge *edge = context->ROLE(ShortestEdgeRole).getShortestEdgeByIndex(i);
			int nodeIndex = context->ROLE(NodeMapRole).getNodeIndexInBestGraph(i);
			int weight = ROLE(AlgorithmRole).calcWeight(*this, nodeIndex, edge);
			if(weight < lowestWeight)
			{
				lowestWeight = weight;
				index = i;
			}
		}
	}

	if(INVALID_VALUE != index)
	{
		updateBestGraph(index);
		totalWeight += lowestWeight;
	}
}
