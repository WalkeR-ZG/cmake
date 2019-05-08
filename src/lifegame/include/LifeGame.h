#ifndef INCLUDE_LIFEGAME_H_
#define INCLUDE_LIFEGAME_H_

#include "infra/Role.h"
#include "trans/Service.h" /*这里添加其头文件是为了对客户只暴漏LifeGame.h这个头文件*/
#include "trans/CellTrans.h"

DEFINE_ROLE(LifeGame){
	static LifeGame& getInstance();
	USE_ROLE(CellTrans);
	USE_ROLE(Service);
};

#endif
