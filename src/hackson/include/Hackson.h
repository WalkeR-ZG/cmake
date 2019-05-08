#ifndef INCLUDE_HACKSON_HACKSON_H_
#define INCLUDE_HACKSON_HACKSON_H_

#include "infra/Role.h"
#include "domain/Graph.h"
#include "domain/BestGraph.h"
#include "trans/Service.h"
#include "domain/AlgorithmRole.h"

struct Hackson : private Graph
			   , private BestGraph
			   , private Service
{
public:
	Hackson(AlgorithmRole* alg);
	void exec();
	IMPL_ROLE(BestGraph);
	IMPL_ROLE(Service);
private:
	AlgorithmRole* alg;
	IMPL_ROLE(Graph);
	IMPL_ROLE_WITH_VAR(AlgorithmRole, alg);
};
#endif
