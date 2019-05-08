#ifndef INCLUDE_HACKSON_DOMAIN_BESTGRAPH_H_
#define INCLUDE_HACKSON_DOMAIN_BESTGRAPH_H_

#include "domain/GraphRole.h"

struct AlgorithmRole;
struct Graph;
struct ContextRole;

struct BestGraph : GraphRole
{
public:
	int getTotalWeight() const;
	void exec();
	friend std::ostream &operator<< (std::ostream& os , const BestGraph& graph);

private:
    void updateBestGraph(const int indexInGraph);
	void execOneRound();
	void initBestGraph();
	USE_ROLE(Graph);
	USE_ROLE(AlgorithmRole);

private:
	int totalWeight;
	ContextRole* context;
};

#endif
