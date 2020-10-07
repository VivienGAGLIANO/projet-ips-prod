#include "../headers/MathTools.h"
#include <boost/math/quadrature/gauss.hpp> // scientific library used to get gaussian quadrature tabulated values
/**
 * @file MathTools.cpp
 */


double MathTools::integrate(double f(double)) {
	return boost::math::quadrature::gauss<double, 25>::integrate(f, -1, 1);
}


/**
 * Computes the factorial
 * 
 * This recursive function computes the factorial of n
 * 
 * @param n integer to computes the factorial of
 */
int MathTools::factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n-1);
}