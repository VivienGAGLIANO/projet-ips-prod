// Simple test to check density computing with naive algorithm

#include <cxxtest/TestSuite.h>
#include "../headers/NaiveRho.h"
#include "../headers/OptimizedRho.h"
#include <chrono>
#include <armadillo>

class TestNaiveRho : public CxxTest::TestSuite {
    public:
    void testNaiveRho_density(void) {
        auto start = std::chrono::steady_clock::now();
        arma::vec zVals = arma::linspace(-20, 20, 64);
        arma::vec rVals = arma::linspace(0, 10, 16);
        auto step1 = std::chrono::steady_clock::now();
        arma::mat densityOptimized = OptimizedRho::density(zVals, rVals);
        auto step2 = std::chrono::steady_clock::now();
        arma::mat densityNaive = NaiveRho::density(zVals, rVals);
        auto step3 = std::chrono::steady_clock::now();
        std::cout << std::endl << arma::approx_equal(densityOptimized, densityNaive, "reldiff", 0.001);

        std::cout << std::endl << "Fill : " << ((std::chrono::duration<double>)(step1 - start)).count() << " s\nOpti algo : " << ((std::chrono::duration<double>) (step2 - step1)).count() << " s\nNaive algo : " << ((std::chrono::duration<double>)(step3 - step2)).count() << " s\n";
    }
};
