#include "gtest/gtest.h"
#include <fstream>
#include <string>
#include "Hackson.h"

using namespace std;

class HacksonTest : public testing::Test
{
};
const string NODE_FILE = "nodes.txt";
const string EDGE_FILE = "edges.txt";
const string SINGEVERTRX_PATH = "hackson/resource/data-SingleRoot/";
const string MULTIVERTRX_PATH = "hackson/resource/data-MultiRoots/";
const string BIGDATA_PATH = "hackson/resource/data-big/";
const string BIGDATA_OUTPUT_PATH = "hackson/output/data-big/";
const string SINGEVERTRX_OUTPUT_PATH = "hackson/output/data-SingleRoot/";
const string RESAULT_NAME = "/result.txt";

#define NEW_INSTANCE(ALG)          Hackson* hackson = new Hackson(_##ALG())
#define INIT_GRAPH(PATH)           hackson->getService().InitGraph(((PATH + NODE_FILE).c_str()), ((PATH + EDGE_FILE).c_str()))
#define FORM_BEST_GRAPH            hackson->exec()
#define OUTPUT_RESULT(PATH, NAME)  hackson->getService().outBestGraphToFile((PATH + NAME).c_str())
#define GET_TOTAL_WEIGHT           hackson->getBestGraph().getTotalWeight()
#define DELETE_INSTANCE            delete hackson
#define HACKSONTEST(ALG, FLG, FOLDER, WEIGHT) \
			NEW_INSTANCE(ALG);                     \
			INIT_GRAPH(FLG##_PATH);                      \
			FORM_BEST_GRAPH;                       \
			OUTPUT_RESULT((FLG##_OUTPUT_PATH + FOLDER), RESAULT_NAME);       \
			EXPECT_EQ(GET_TOTAL_WEIGHT, WEIGHT);   \
			DELETE_INSTANCE;

TEST_F(HacksonTest, Prim1_SingleVertex)
{
	HACKSONTEST(Prim1, SINGEVERTRX, "req1", 87);
}

TEST_F(HacksonTest, Prim2_SingleVertex)
{
	HACKSONTEST(Prim2, SINGEVERTRX, "req2", 123);
}

TEST_F(HacksonTest, Prim3_SingleVertex)
{
	HACKSONTEST(Prim3, SINGEVERTRX, "req3", 222);
}

TEST_F(HacksonTest, Prim4_SingleVertex)
{
	HACKSONTEST(Prim4, SINGEVERTRX, "req4", 285);
}

TEST_F(HacksonTest, Prim1_BigDATA)
{
	HACKSONTEST(Prim1, BIGDATA, "req1", 7072);
}

TEST_F(HacksonTest, Prim2_BigDATA)
{
	HACKSONTEST(Prim2, BIGDATA, "req2", 8986);
}

TEST_F(HacksonTest, Prim3_BigDATA)
{
	HACKSONTEST(Prim3, BIGDATA, "req3", 14303);
}

TEST_F(HacksonTest, Prim4_BigDATA)
{
	HACKSONTEST(Prim4, BIGDATA, "req4", 18361);
}
