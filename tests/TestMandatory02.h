// Mandatory test #02 - Basis r-functions

#include <cxxtest/TestSuite.h>
#include "../headers/Basis.h"
#include <armadillo>

class TestMandatory02 : public CxxTest::TestSuite {
    public:
    void testBasis_rFunctions(void) {
        // Mandatory test #02 - Basis r-functions
        // br = 1.935801664793151, bz = 2.829683956491218, N = 14, Q = 1.3
        Basis basis(1.935801664793151,      2.829683956491218,     14,     1.3);
        arma::vec r = {3.1, 2.3, 1.0, 0.0, 0.1, 4.3, 9.2, 13.7};
        arma::vec res00 = { 8.08521235111303e-02,
                            1.43887615825118e-01,
                            2.55045100912706e-01,
                            2.91450097294984e-01,
                            2.91061479407116e-01,
                            2.47240792330589e-02,
                            3.63004153921473e-06,
                            3.87659726026123e-12};
        TS_ASSERT_DELTA(arma::norm(basis.rPart(r, 0, 0) - res00), 0.0, 1e-15);
        arma::vec res82 = { 5.87858442372438e-02,
                            1.35240488413384e-02,
                            4.06810074575519e-05,
                            0.00000000000000e+00,
                            4.92817669085478e-13,
                            8.52011998934850e-02,
                            5.20525909328609e-02,
                            1.44615166152252e-05};
        TS_ASSERT_DELTA(arma::norm(basis.rPart(r, 8, 2) - res82), 0.0, 1e-15);
    }
};

