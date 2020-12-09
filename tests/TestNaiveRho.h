// Simple test to check density computing with naive algorithm

#include <cxxtest/TestSuite.h>
#include "../headers/NaiveRho.h"
#include "../headers/Basis.h"
#include <armadillo>

class TestNaiveRho : public CxxTest::TestSuite {
    public:
    void testNaiveRho_density(void) {
        arma::vec rVals(16);
        for (int i = 0; i < 16; ++i) {
            rVals(i) = ((double) 10 * i / 16);
        }
        arma::vec zVals(64);
        for (int i = 0; i < 64; ++i) {
            zVals(i) = ((double) 40 * i / 64 - 20);
        }
        arma::mat density = NaiveRho::density(zVals, rVals);
        std::cout << std::endl << density;
    }
};
