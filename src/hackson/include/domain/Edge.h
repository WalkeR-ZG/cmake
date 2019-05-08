#ifndef INCLUDE_HACKSON_DOMAIN_EDGE_H_
#define INCLUDE_HACKSON_DOMAIN_EDGE_H_

#include <string>

struct Edge
{
	Edge(int nodeIndex, int weight, Edge *nextEdge = NULL);

    int nodeIndex;         //该边所指向的顶点的在图中位置
    int weight;            //边的相应权值
    Edge *nextEdge; //指向下一条边的指针
};

#endif
