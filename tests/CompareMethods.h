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

        double time1 = ((std::chrono::duration<double>)(step2 - step1)).count();
        double time2 = ((std::chrono::duration<double>) (step3 - step2)).count();

        std::cout << std::endl << "Results equality : " << arma::approx_equal(densityOptimized, densityNaive, "reldiff", 0.001);
        std::cout << std::endl << "Fill : " << ((std::chrono::duration<double>)(step1 - start)).count() << " s\nNaive algorithm : " << time2 << " s\nOptimized algorithm : " << time1 << " s\n";
        std::cout << "Optimisation : " << time2/time1 << std::endl;
    }
};
