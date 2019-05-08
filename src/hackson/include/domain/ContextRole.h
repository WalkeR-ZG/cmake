#ifndef INCLUDE_HACKSON_DOMAIN_CONTEXTROLE_H_
#define INCLUDE_HACKSON_DOMAIN_CONTEXTROLE_H_

#include "infra/Role.h"

struct NodeMapRole;
struct ShortestEdgeRole;
struct Graph;
struct BestGraph;

DEFINE_ROLE(ContextRole)
{
public:
	HAS_ROLE(NodeMapRole);
	HAS_ROLE(ShortestEdgeRole);
	void formShortestEdgeBetweenTwoGraph(const Graph& graph, const BestGraph& bestGraph);
};

#endif
