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
arma::colvec Schrodinger::psi(int n, arma::colvec z) {
    Hermit hermit(sqrt(m*w/h_bar) * z);
    return (1 / sqrt(pow(2, n) * MathTools::factorial(n))) * pow((m*w)/(pi*h_bar), 0.25) * exp(-m*w*z*z / (2*h_bar)) * hermit.get(n);
}

arma::colvec Schrodinger::psi_second(int n, arma::colvec z){
    arma::vec h_vec = arma::vec(z.n_rows).ones();
    return (psi(n, z + h_vec) - psi(n, z)) % ((1 / h*h) * arma::vec(z.n_rows).ones()) - (psi(n, h_vec) - psi(n, h_vec)) % ((1 / h) * (arma::vec(z.n_rows).ones()));

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