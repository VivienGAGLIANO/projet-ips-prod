#include <cxxtest/TestSuite.h>
#include "../src/Schrodinger.cpp"

class TestSchrodinger : public CxxTest::TestSuite
{
	public:
	void testSchrodinger(void)
	{
		Schrodinger schro;
	       	TS_ASSERT_EQUALS(schro.solution(5,4.5,/* JSP wallah*/));
		TS_ASSERT_EQUALS(schro.solution(5,4.5,/* JSP wallah*/));
		TS_ASSERT_EQUALS(schro.solution(5,4.5,/* JSP wallah*/));
		TS_ASSERT_EQUALS(schro.solution(5,4.5,/* JSP wallah*/));
		TS_ASSERT_EQUALS(schro.solution(5,4.5,/* JSP wallah*/));
		TS_ASSERT_EQUALS(schro.solution(5,4.5,/* JSP wallah*/));
		TS_ASSERT_EQUALS(schro.solution(5,4.5,/* JSP wallah*/));
	}
};
