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
            rVals(i) = ((double) 10 * i / 16)*1E-15;
        }
        arma::vec zVals(64);
        for (int i = 0; i < 64; ++i) {
            zVals(i) = ((double) 40 * i / 64 - 20)*1E-15;
        }
        Basis basis(1.935801664793151,      2.829683956491218,     14,     1.3);
        std::cout << basis.basisFunc(0, 0, 1, zVals, rVals);
        //arma::mat density = NaiveRho::density(rVals, zVals);
        //std::cout << std::endl << density;
    }
};
