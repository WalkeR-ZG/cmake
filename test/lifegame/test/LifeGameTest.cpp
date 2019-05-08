#include <string.h>
#include "gtest/gtest.h"
#include "LifeGame.h"

class LifeGameTest:public testing::Test
{};

TEST_F(LifeGameTest,life_change_complete_initdata3)
{
	LifeGame::getInstance().ROLE(Service).InitLifeCell(R"(lifegame/resource/input/initdata3.txt)", 3, 3);
	LifeGame::getInstance().ROLE(CellTrans).oneRoundCellChange();
    EXPECT_EQ("$ $$   $$", LifeGame::getInstance().ROLE(Service).LifeCellStateConvertToString(R"(lifegame/resource/output/Final3.txt)"));
}

TEST_F(LifeGameTest,life_change_complete_to_a_stable_state_initdata20)
{
	LifeGame::getInstance().ROLE(Service).InitLifeCell(R"(lifegame/resource/input/initdata20.txt)", 20, 20);
	LifeGame::getInstance().ROLE(CellTrans).changeCompelete();
    EXPECT_EQ("                                                                       $$     $$           $$     $$                                        $$                  $$                                                                                                                                                                          $$             $$   $$             $$                               ", LifeGame::getInstance().ROLE(Service).LifeCellStateConvertToString(R"(lifegame/resource/output/Final20.txt)"));
}
