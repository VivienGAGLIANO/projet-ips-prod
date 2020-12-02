// Simple test to check density computing with naive algorithm

#include <cxxtest/TestSuite.h>
#include "../headers/NaiveRho.h"
#include <armadillo>

class TestNaiveRho : public CxxTest::TestSuite {
    public:
    void testNaiveRho_density(void) {
        arma::vec rVals(32);
        for (int i = 0; i < 32; ++i) {
            rVals(i) = (-10+((double) 20 * i / 32))*1E-15;
        }

        arma::mat density = NaiveRho::density(rVals, rVals);
        std::cout << std::endl << density;
    }
};
