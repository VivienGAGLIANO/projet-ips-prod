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
 * This function uses the recursion relation definition of the hermit polynoms to evaluate the n-th and n+1 th polynom in given z. This avoids computing several times the same values during recursion.
 *
 * @param n rank of the desired polynom
 * @param z evaluation point
 * @return Return value is a vector2 (H_n+1(z), H_n(z))
 */
arma::vec MathTools::fast_hermit(int n, double z) {
    if (n == 0) {
        return {2*z, 1}; 
    }
    if (n == 1) {
        return {4*pow(z, 2) - 2*z, 2*z};
    }
    arma::vec prev = fast_hermit(n - 1, z);
    arma::rowvec rec = {2*z, (double)-2*(n - 1)};
    arma::vec next = rec*prev;
    arma::vec result = {next(0), prev(1)};
    return result;
    }

/**
 * Accessor for n-th hermit polynom
 * 
 * @param n rank of the desired polynom
 * @param z evaluation point
 * @return Returns evaluation of n-th polynom in z
 */
double MathTools::hermit(int n, double z) {
    return fast_hermit(n, z)(1);
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