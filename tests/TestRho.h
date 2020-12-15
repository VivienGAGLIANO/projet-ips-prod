// test rho -

#include <cxxtest/TestSuite.h>
#include "../headers/OptimizedRho.h"
#include "../headers/NaiveRho.h"
#include <armadillo>

class TestMandatory00 : public CxxTest::TestSuite {
    public:
    void testNaiveRho(void) {
        // test naive rho calculation
        arma::vec zVals = {5.396825, -6.666667, 0.952381, 7.301587};
        arma::vec rVals = {2.903226, -4.838710, -2.258065, 6.774194};
        arma::mat density = NaiveRho::density(zVals, rVals);
        TS_ASSERT_DELTA(density(0, 0), 0.149483, 1e-06);
        TS_ASSERT_DELTA(density(1, 1), 0.042846, 1e-06);
        TS_ASSERT_DELTA(density(2, 2), 0.146820, 1e-06);
        TS_ASSERT_DELTA(density(3, 3), 0.001511, 1e-06);
    }
    void testOptimizedRho(void) {
        // test optimized rho calculation
        arma::vec zVals = {5.396825, -6.666667, 0.952381, 7.301587};
        arma::vec rVals = {2.903226, -4.838710, -2.258065, 6.774194};
        arma::mat density = OptimizedRho::density(zVals, rVals);
        TS_ASSERT_DELTA(density(0, 0), 0.149483, 1e-06);
        TS_ASSERT_DELTA(density(1, 1), 0.042846, 1e-06);
        TS_ASSERT_DELTA(density(2, 2), 0.146820, 1e-06);
        TS_ASSERT_DELTA(density(3, 3), 0.001511, 1e-06);
    }
};
