#include "domain/AlgorithmRole.h"
#include "domain/Node.h"
#include "domain/Edge.h"
#include "domain/BestGraph.h"

#include <iostream>
using namespace std;


#define IMPL_CALCWEIGHT  OVERRIDE(int calcWeight(const BestGraph& bestGraph, const int indexInBestGraph, const Edge* edge) const)
#define IMPL_INIT        OVERRIDE(void init())
#define IMPL_UPDATE      OVERRIDE(void update(const BestGraph& bestGraph, const std::string& nodeName))

struct Prim1 : AlgorithmRole
{
public:
	IMPL_CALCWEIGHT
	{
	    return edge->weight;
	}
};

struct AlgDecoratorRole : AlgorithmRole
{
public:
	AlgDecoratorRole(AlgorithmRole* alg) : alg(alg) {};
protected:
	AlgorithmRole* alg;
};

#define BEGIN_IMPL_ALG(NAME)                             \
struct NAME : AlgDecoratorRole                           \
{                                                        \
public:                                                  \
    NAME(AlgorithmRole* alg) : AlgDecoratorRole(alg){};

#define END_IMPL_ALG   };

BEGIN_IMPL_ALG(Prim2)
    IMPL_CALCWEIGHT
	{
		int weight = getNodeConnectionNumExceptFather(bestGraph, indexInBestGraph);
		weight = (weight > 10 ? 10 : weight);
		return weight + alg->calcWeight(bestGraph, indexInBestGraph, edge);
	}
private:
	int getNodeConnectionNumExceptFather(const BestGraph& bestGraph, const int indexInBestGraph) const
	{
		int connection = 0;

		Edge* edge = bestGraph.getNodeByIndex(indexInBestGraph)->firstEdge;
		while(edge != NULL)
		{
			connection++;
			edge = edge->nextEdge;
		}
		return bestGraph.getNodeByIndex(indexInBestGraph)->isVertex ? connection + 1: connection ; //如果非顶点则减去父节点
	}
END_IMPL_ALG

BEGIN_IMPL_ALG(Prim3)
    IMPL_CALCWEIGHT
	{
		int weight = getNodeDepth(bestGraph, indexInBestGraph);
		weight = (weight > 10 ? 10 : weight);
		return weight + alg->calcWeight(bestGraph, indexInBestGraph, edge);
	}

    IMPL_INIT
	{
		for(int i = 0; i < MAX_NODE_NUM; i++)
		{
			fatherNode[i] = 0xFFFF;
		}
	}

	IMPL_UPDATE
	{
		alg->update(bestGraph, nodeName);
		int index = bestGraph.locateNode(nodeName);
		fatherNode[bestGraph.getAllNodeNum() - 1] = index;
	}

	int getFatherNode(const int nodeIndex) const
	{
		return fatherNode[nodeIndex];
	}

private:
	int getNodeDepth(const BestGraph& bestGraph, const int indexInBestGraph) const
	{
		int depth = 0;
		int index = indexInBestGraph;
		Node * node = bestGraph.getNodeByIndex(indexInBestGraph);

		while(node->isVertex != true)
		{
			node  = bestGraph.getNodeByIndex(fatherNode[index]);
			index = fatherNode[index];
			depth++;
		}
		return depth + 1;
	}

private:
	int fatherNode[MAX_NODE_NUM];//在最小生成树里，一个节点最多只有一个父亲
END_IMPL_ALG

BEGIN_IMPL_ALG(Prim4)
    IMPL_CALCWEIGHT
	{
		int weight = 2;
		int index = indexInBestGraph;

		while(index < bestGraph.getAllNodeNum())
		{
			int totalSon = getSonNum(index);
			if((0 == totalSon % 5)&&(totalSon <= 20)&&(totalSon >= 5))
			{
				weight += 2;
			}
			index = getFatherNode(index);
		}
		return weight + alg->calcWeight(bestGraph, indexInBestGraph, edge);
	}

	IMPL_INIT
	{
		alg->init();
		for(int i = 0; i < MAX_NODE_NUM; i++)
		{
			sonNodeNum[i] = 0;
		}
	}

	IMPL_UPDATE
	{
		alg->update(bestGraph, nodeName);
		int index = bestGraph.getAllNodeNum() - 1;
		Node * node = bestGraph.getNodeByIndex(index);
		while(node->isVertex != true)
		{
			sonNodeNum[getFatherNode(index)]++;
			node  = bestGraph.getNodeByIndex(getFatherNode(index));
			index = getFatherNode(index);
		}
	}
private:
	int getSonNum(const int nodeIndex) const
	{
		return sonNodeNum[nodeIndex];
	}

	int getFatherNode(const int nodeIndex) const
	{
		return ((Prim3*)alg)->getFatherNode(nodeIndex);
	}
private:
	int sonNodeNum[MAX_NODE_NUM];//在最小生成树里，每个节点的子孙节点个数
};

static AlgorithmRole * __Prim1 = new Prim1();
static AlgorithmRole * __Prim2 = new Prim2(__Prim1);
static AlgorithmRole * __Prim3 = new Prim3(__Prim2);
static AlgorithmRole * __Prim4 = new Prim4(__Prim3);

#define IMPL_ALG_INSTANCE(NAME) \
AlgorithmRole* const _##NAME()  \
{                               \
	return __##NAME;            \
}
IMPL_ALG_INSTANCE(Prim1)
IMPL_ALG_INSTANCE(Prim2)
IMPL_ALG_INSTANCE(Prim3)
IMPL_ALG_INSTANCE(Prim4)
