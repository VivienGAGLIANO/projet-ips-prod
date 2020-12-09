// Simple test to check density computing with naive algorithm

#include <cxxtest/TestSuite.h>
#include "../headers/NaiveRho.h"
#include <chrono>
#include <armadillo>

class TestNaiveRho : public CxxTest::TestSuite {
    public:
    void testNaiveRho_density(void) {
        auto start = std::chrono::steady_clock::now();
        arma::vec zVals = arma::linspace(-20, 20, 64);
        arma::vec rVals = arma::linspace(0, 10, 16);
        auto step1 = std::chrono::steady_clock::now();
        arma::mat density = NaiveRho::density(zVals, rVals);
        auto step2 = std::chrono::steady_clock::now();
        //std::cout << std::endl << density;

        std::cout << std::endl << "Fill : " << ((std::chrono::duration<double>)(step1 - start)).count() << " s\nNaive algo : " << ((std::chrono::duration<double>) (step2 - step1)).count() << " s\n";
    }
};
