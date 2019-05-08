#ifndef INCLUDE_HACKSON_DOMAIN_ALGORITHMROLE_H_
#define INCLUDE_HACKSON_DOMAIN_ALGORITHMROLE_H_

#include <string>
#include "infra/Role.h"

struct BestGraph;
struct Edge;

DEFINE_ROLE(AlgorithmRole)
{
public:
	ABSTRACT(int calcWeight(const BestGraph& bestGraph, const int indexInBestGraph, const Edge* edge) const);
	virtual void update(const BestGraph& bestGraph, const std::string& nodeName) {};
	virtual void init() {};
};

#define DECL_ALG(NAME) AlgorithmRole* const _##NAME()
DECL_ALG(Prim1);
DECL_ALG(Prim2);
DECL_ALG(Prim3);
DECL_ALG(Prim4);
#endif
