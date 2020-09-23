#include "../headers/MathTools.h"

/**
 * @file MathTools.cpp
 */


double MathTools::integrate(double f(double)) {
	return 0;
}

/**
 * Computes and evaluates hermit polynom
 * 
 * This function uses the recursion relation definition of the hermit polynoms to evaluate the n-th polynom in given z
 *
 * @param n rank of the desired polynom
 * @param z evaluation point
 */
double MathTools::hermit(int n, double z) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2 * z;
    }
    return 2 * z * hermit(n - 1, z) - 2 * (n - 1) * hermit(n - 2, z);
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
