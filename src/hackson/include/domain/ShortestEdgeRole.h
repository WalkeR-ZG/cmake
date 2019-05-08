#ifndef INCLUDE_HACKSON_DOMAIN_SHORTESTEDGEROLE_H_
#define INCLUDE_HACKSON_DOMAIN_SHORTESTEDGEROLE_H_

#include "infra/Role.h"
#include "infra/Base.h"

struct Edge;

DEFINE_ROLE(ShortestEdgeRole)
{
public:
	void setShortestEdgeByIndex(const int index, const Edge* edge);
	bool hasEdgeBetweenTwoGraphByIndex(const int index) const;
	Edge* getShortestEdgeByIndex(const int index) const;

private:
	Edge*  shortestEdge[MAX_NODE_NUM]; //局部最优生成树的点到原始图剩余点权值最小的边
};

#endif
