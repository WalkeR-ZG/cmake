#include "domain/Node.h"

Node :: Node(std::string &name,bool& isVertex, Edge *firstEdge)
                     : name(name)
					 , isVertex(isVertex)
					 , firstEdge(firstEdge)
{
}
