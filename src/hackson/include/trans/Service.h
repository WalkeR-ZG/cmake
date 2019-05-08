#ifndef INCLUDE_HACKSON_TRANS_SERVICE_H_
#define INCLUDE_HACKSON_TRANS_SERVICE_H_

#include "infra/Role.h"
#include <string>

struct Graph;
struct BestGraph;

DEFINE_ROLE(Service)
{
public:
	void InitGraph(const char* nodesPath, const char* edgesPath) const;
	void outBestGraphToFile(const char *s) const;
private:
	USE_ROLE(Graph);
	USE_ROLE(BestGraph);
	void addNode(const std::string str) const;
	void addEdge(const std::string str) const;
};

#endif
