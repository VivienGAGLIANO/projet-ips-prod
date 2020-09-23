#include <cxxtest/TestSuite.h>
#include "../src/MathTools.cpp"

class TestMathTools : public CxxTest::TestSuite
{
	public:
	void testHermit(void)
	{
		MathTools Tools = new MathTools(); 
		TS_ASSERT_EQUALS(Tools.hermit(0,0),1);
		TS_ASSERT_EQUALS(MathTools::hermit(1,2),4);
		TS_ASSERT_EQUALS(MathTools::hermit(1,4),8);
		TS_ASSERT_EQUALS(MathTools::hermit(4,2),76);
		TS_ASSERT_EQUALS(MathTools::hermit(4,-2),76);
		TS_ASSERT_EQUALS(MathTools::hermit(4,0),12);
		TS_ASSERT_EQUALS(MathTools::hermit(5,2),-16);
		TS_ASSERT_EQUALS(MathTools::hermit(5,-2),16);
		TS_ASSERT_EQUALS(MathTools::hermit(5,2),0);
		TS_ASSERT_EQUALS(MathTools::hermit(6,2),-824);
		TS_ASSERT_EQUALS(MathTools::hermit(6,-2),-824);
		TS_ASSERT_EQUALS(MathTools::hermit(6,0),-120);
	}
};
