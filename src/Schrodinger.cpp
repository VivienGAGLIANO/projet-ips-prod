#include "../headers/Schrodinger.h"
#include "../headers/MathTools.h"
#include "../headers/Hermit.h"
#include <cmath>

/**
 * @file Schrodinger.cpp
 */


/**
 * Vectorized solution of the Schrodinger equation
 *
 * @param n
 * @param z
 */
arma::colvec Schrodinger::solution(int n, arma::rowvec z) {
    Hermit hermit(sqrt(m*w/h) * z);
    return (1 / sqrt(pow(2, n) * MathTools::factorial(n))) * pow((m*w)/(pi*h), 0.25) * exp(-m*w*z*z / (2*h)) * hermit.get(n);
}


/**
 * Checks the orthonormality 
 */
bool Schrodinger::orthonormality() {
    for (int m = 0; m <= 10; m++) {
        for (int n = 0; n <= 10; n++) {
            // TODO
            // if (MathTools::integrate() != (m == n) ? 1 : 0) {
            //     return false;
            // }
        }
    }
    return true;
}