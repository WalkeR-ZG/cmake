#include <iostream>
#include <fstream>
#include "domain/GraphRole.h"
#include "domain/Edge.h"
#include "domain/Node.h"

using namespace std;

GraphRole :: GraphRole()
{
//	memset(allNode, 0, MAX_NODE_NUM *sizeof(Node*));
	allNodeNum = 0;
}

GraphRole :: ~GraphRole()
{
	for(int i = 0; i < allNodeNum; i++)
	{
		Edge* edge = allNode[i]->firstEdge;
		while(edge != NULL)
		{
			Edge* tmp = edge;
			edge = edge->nextEdge;
			delete tmp;
		}
	}
	for(int i = 0; i < allNodeNum; i++)
	{
		delete allNode[i];
	}
	nameIndexMap.clear();
}

void GraphRole :: addNode(Node* node)
{
	allNode[allNodeNum] = node;
	nameIndexMap.insert(pair<string, int> (node->name, allNodeNum++));
}

void GraphRole :: addEdge(const std::string& endPoint1, const std::string& endPoint2, const int weight)
{
    int i = locateNode(endPoint1);
    int j = locateNode(endPoint2);
    Edge* edge1 = new Edge(j, weight, allNode[i]->firstEdge);
    Edge* edge2 = new Edge(i, weight, allNode[j]->firstEdge);
    allNode[i]->firstEdge = edge1;
    allNode[j]->firstEdge = edge2;
}

int GraphRole :: locateNode(const std::string& nodeName) const
{
	return nameIndexMap.find(nodeName)->second;
}

Node* GraphRole :: getNodeByIndex(const int index) const
{
	return index < allNodeNum ? allNode[index] : NULL;
}

int GraphRole :: getAllNodeNum() const
{
	return allNodeNum;
}
