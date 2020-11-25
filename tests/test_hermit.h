#include <cxxtest/TestSuite.h>
#include "../src/Poly.cpp"

class TestHermit : public CxxTest::TestSuite
{
	public:
	void testHermit(void)
	{
	    Poly poly;
	    poly.calcHermite(6, arma::colvec({-2, 0, 2}));
	    TS_ASSERT_EQUALS(poly.hermite(0)(0),1);
		TS_ASSERT_EQUALS(poly.hermite(0)(1),1);
		TS_ASSERT_EQUALS(poly.hermite(0)(2),1);
		TS_ASSERT_EQUALS(poly.hermite(1)(2),4);
		TS_ASSERT_EQUALS(poly.hermite(1)(0),-4);
		TS_ASSERT_EQUALS(poly.hermite(4)(2),76);
		TS_ASSERT_EQUALS(poly.hermite(4)(0),76);
		TS_ASSERT_EQUALS(poly.hermite(4)(1),12);
		TS_ASSERT_EQUALS(poly.hermite(5)(2),-16);
		TS_ASSERT_EQUALS(poly.hermite(5)(0),16);
		TS_ASSERT_EQUALS(poly.hermite(5)(1),0);
		TS_ASSERT_EQUALS(poly.hermite(6)(2),-824);
		TS_ASSERT_EQUALS(poly.hermite(6)(0),-824);
		TS_ASSERT_EQUALS(poly.hermite(6)(1),-120);
	}
};
