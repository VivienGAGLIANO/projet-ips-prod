#include "../headers/MathTools.h"
/**
 * @file MathTools.cpp
 */


double MathTools::integrate(double f(double)) {
	return f(0);
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

std::function<double(double)> MathTools::differentiate(std::function<double(double)> f) {
    return [f](double z) {return (f(z + h) - f(z)) / h;};
}

std::function<arma::colvec(arma::colvec)> MathTools::differentiate(std::function<arma::colvec(arma::colvec)> f) {
    return [f](arma::colvec z)
        {
            arma::colvec h_vec = h * arma::colvec(z.n_rows).ones();
            return (1 / h) * (f(z + h_vec) - f(z));
        };

}