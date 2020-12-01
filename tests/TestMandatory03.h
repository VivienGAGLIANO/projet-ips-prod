// Mandatory test #03 - Basis z-functions

#include <cxxtest/TestSuite.h>
#include "../headers/Basis.h"
#include <armadillo>

class TestMandatory03 : public CxxTest::TestSuite {
    public:
    void testBasis_zFunctions(void) {
        // Mandatory test #03 - Basis z-functions
        // br = 1.935801664793151, bz = 2.829683956491218, N = 14, Q = 1.3
        Basis basis(1.935801664793151,      2.829683956491218,     14,     1.3);
        arma::vec z = {-10.1, -8.4, -1.0, 0.0, 0.1, 4.3, 9.2, 13.7};
        arma::vec res00 = { 7.64546544834383e-04,
                            5.44886272162148e-03,
                            4.19492564268520e-01,
                            4.46522724110539e-01,
                            4.46243982300708e-01,
                            1.40736821086932e-01,
                            2.26186220733178e-03,
                            3.62929640195959e-06};
        TS_ASSERT_DELTA(arma::norm(basis.zPart(z, 0) - res00), 0.0, 1e-15);
        arma::vec res15 = {-9.48674551049192e-02,
                           -1.40338701953237e-03,
                           1.85620628040096e-01,
                           -0.00000000000000e+00,
                           -3.93028470685214e-02,
                           -1.79526868763440e-01,
                           2.15604096600475e-01,
                           2.44977220882127e-01};
        TS_ASSERT_DELTA(arma::norm(basis.zPart(z, 15) - res15), 0.0, 1e-15);
    }
};

