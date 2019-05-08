#ifndef INCLUDE_HACKSON_DOMAIN_NODE_H_
#define INCLUDE_HACKSON_DOMAIN_NODE_H_

#include <string>
struct Edge;

struct Node{
	Node(std::string &name, bool& isVertex, Edge *firstEdge = NULL);

    std::string name;    //顶点名称
    bool isVertex;       //是否为顶点
    Edge* firstEdge;     //边表头指针
};

#endif
