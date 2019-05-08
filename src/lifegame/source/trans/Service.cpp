#include "trans/Service.h"
#include "domain/CellMap.h"
#include "domain/Cell.h"
#include <fstream>
#include <iostream>

using namespace std;

void Service::InitLifeCell(const char* intFilePath, const int row, const int column) const
{
	ROLE(CellMap).initCellMap(GetString(intFilePath), row, column);
}

string Service::LifeCellStateConvertToString(const char *s) const
{
	ofstream out(s);
	out<<ROLE(CellMap);
	out.close();
	return GetString(s);
}

string Service::GetString(const char *s) const
{
	ifstream in(s);
	string rst;
	string str;

	while(getline(in,str))
	{
		rst += str;
		if(rst[rst.size()-1] == '\r')
		{
			rst = rst.substr(0, rst.size()-1);
		}
	}
	in.close();
	return rst;
}
