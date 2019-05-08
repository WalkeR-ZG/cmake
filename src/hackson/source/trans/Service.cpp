#include <iostream>
#include <fstream>
#include <cstdlib>

#include "trans/Service.h"
#include "domain/Graph.h"
#include "domain/BestGraph.h"
#include "domain/Node.h"
#include "infra/Role.h"

using namespace std;

#define INIT_GRAPH_BY_FILE(FILE, METHOD)  do{ \
	        ifstream in(FILE);                \
	        string str;                       \
	        while(getline(in,str))            \
            {                                 \
	        	METHOD(str);                  \
	        }                                 \
	        in.close();                       \
        }while(0);

void Service :: addNode(const string str) const
{
	string nodeName = str.substr(0,str.find(","));
	bool isVertex = ("Y" == str.substr(str.find(",") + 1, 1));
	ROLE(Graph).addNode(new Node(nodeName, isVertex));
}

void Service:: addEdge(const string str) const
{
	int second = str.find_last_of(",");
	int first = str.find_first_of(",");
	ROLE(Graph).addEdge(str.substr(0,first)
		                , str.substr(first + 1, second - first - 1)
						, atoi(str.substr(second + 1, str.size() - second - 1).c_str()));
}

void Service::InitGraph(const char* nodesPath, const char* edgesPath) const
{
	INIT_GRAPH_BY_FILE(nodesPath, addNode);
	INIT_GRAPH_BY_FILE(edgesPath, addEdge);
}

void Service :: outBestGraphToFile(const char *s) const
{
	ofstream out(s);
	out<<ROLE(BestGraph);
	out.close();
}
