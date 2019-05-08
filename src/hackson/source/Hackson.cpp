#include "Hackson.h"

#include <iostream>
using namespace std;

Hackson :: Hackson(AlgorithmRole* alg) : alg(alg)
{
}

void Hackson :: exec()
{
	ROLE(BestGraph).exec();
}
