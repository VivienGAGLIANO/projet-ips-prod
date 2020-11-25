// Mandatory test #00 - Hermite and Laguerre polynomials

#include <cxxtest/TestSuite.h>
#include "../headers/Poly.h"
#include <armadillo>

class TestMandatory00 : public CxxTest::TestSuite {
    public:
    void testPoly(void) {
        Poly poly;
        arma::vec zVals = {-3.1, -2.3, -1.0, -0.3, 0.1, 4.3, 9.2, 13.7};
        poly.calcHermite(6, zVals); // compute Hermite polynomials for n in {0 ... 5}
        arma::vec calcVals   = poly.hermite(4); // n = 4
        arma::vec targetVals = {  1.02835360e+03,  2.05825600e+02, -2.00000000e+01,  7.80960000e+00,
                        1.15216000e+01,  4.59456160e+03,  1.10572154e+05,  5.54643458e+05};
        TS_ASSERT_DELTA(arma::norm(calcVals / targetVals - 1.0), 0.0, 1e-08);
        calcVals   = poly.hermite(5); // n = 5
        targetVals = { -4.76676832e+03, -3.88909760e+02,  8.00000000e+00, -3.17577600e+01,
                       1.18403200e+01,  3.48375818e+04,  1.98557479e+06,  1.50339793e+07};
        TS_ASSERT_DELTA(arma::norm(calcVals / targetVals - 1.0), 0.0, 1e-08);
        zVals = {0.1, 0.3, 1.2, 1.8, 2.0, 2.5, 7.1, 11.1};
        /*
        poly.calcLaguerre(6, 4, zVals); // compute generalized Laguerre polynomials for m in {0 ... 5} and n in {0 ... 3}
        calcVals   = poly.laguerre(4, 2); // m = 4, n = 2
        targetVals = {  14.405,  13.245,  8.52 ,  5.82 ,  5.,  3.125,  -2.395,  10.005};
        TS_ASSERT_DELTA(arma::norm(calcVals / targetVals - 1.0), 0.0, 1e-08);
        calcVals   = poly.laguerre(5, 3); // m = 5, n = 3
        targetVals = { 53.23983333,  47.95550000,  27.87200000,  17.5880,
                       14.66666667,   8.39583333,  -0.81183333,  10.1015};
        TS_ASSERT_DELTA(arma::norm(calcVals / targetVals - 1.0), 0.0, 1e-08);
        */
    }
};

