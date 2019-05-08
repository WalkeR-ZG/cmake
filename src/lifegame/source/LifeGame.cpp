#include "LifeGame.h"
#include "Life.h"
#include "infra/Role.h"

struct LifeGameImpl : LifeGame
					,Service
{
	LifeGameImpl();
	IMPL_ROLE_WITH_VAR(CellTrans,life);
	IMPL_ROLE(Service);
private:
	IMPL_ROLE_WITH_VAR(CellMap,life);
	Life* life;
};

LifeGameImpl::LifeGameImpl()
{
	life = new Life();
}

LifeGame& LifeGame::getInstance()
{
	static LifeGameImpl lifegame;
	return lifegame;
}
