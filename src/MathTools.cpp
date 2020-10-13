#include "../headers/MathTools.h"
/**
 * @file MathTools.cpp
 */


double MathTools::integrate(double f(double)) {
	return 0;
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