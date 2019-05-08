#ifndef INCLUDE_HACKSON_DOMAIN_GRAPHROLE_H_
#define INCLUDE_HACKSON_DOMAIN_GRAPHROLE_H_
#include <string>
#include <map>
#include "infra/Role.h"
#include "infra/Base.h"

struct Node;

DEFINE_ROLE(GraphRole)
{
public:
	GraphRole();
	~GraphRole();
	void addNode(Node* node);
	void addEdge(const std::string& endPoint1, const std::string& endPoint2, const int weight);
	int getAllNodeNum() const;
	Node* getNodeByIndex(const int index) const;
	int locateNode(const std::string& nodeName) const;

private:
	Node* allNode[MAX_NODE_NUM];
	int   allNodeNum;
	std::map <std::string,int> nameIndexMap;
};

#endif
