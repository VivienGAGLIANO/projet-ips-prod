#include <cxxtest/TestSuite.h>
#include "../src/Hermit.cpp"

class TestHermit : public CxxTest::TestSuite
{
	public:
	void testHermit(void)
	{
		Hermit herm(arma::colvec({-2,0,2}));
	    TS_ASSERT_EQUALS(herm.get(0)(0),1);
		TS_ASSERT_EQUALS(herm.get(0)(1),1);
		TS_ASSERT_EQUALS(herm.get(0)(2),1);
		TS_ASSERT_EQUALS(herm.get(1)(2),4);
		TS_ASSERT_EQUALS(herm.get(1)(0),-4);
		TS_ASSERT_EQUALS(herm.get(4)(2),76);
		TS_ASSERT_EQUALS(herm.get(4)(0),76);
		TS_ASSERT_EQUALS(herm.get(4)(1),12);
		TS_ASSERT_EQUALS(herm.get(5)(2),-16);
		TS_ASSERT_EQUALS(herm.get(5)(0),16);
		TS_ASSERT_EQUALS(herm.get(5)(1),0);
		TS_ASSERT_EQUALS(herm.get(6)(2),-824);
		TS_ASSERT_EQUALS(herm.get(6)(0),-824);
		TS_ASSERT_EQUALS(herm.get(6)(1),-120);
	}
};
