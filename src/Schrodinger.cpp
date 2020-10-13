/**
 * @file Schrodinger.cpp
 */


#include "../headers/Schrodinger.h"
#include "../headers/MathTools.h"
#include "../headers/Hermit.h"
#include <cmath>

/**
 * Vectorized solution of the Schrodinger equation
 *
 * @param n energy level
 * @param z mesh on which to evaluate the solution
 * @return the solution computed along given mesh
 */
arma::colvec Schrodinger::psi(int n, arma::colvec z) {
    Hermit hermit(sqrt(m*w/h_bar) * z);
    return (1 / sqrt(pow(2, n) * MathTools::factorial(n))) * pow((m*w)/(pi*h_bar), 0.25) * arma::exp(-m*w*(z%z) / (2*h_bar)) % hermit.get(n);
}

/**
 * Second derivative of Schrodinger equation solution
 *
 * @param n energy level
 * @param z mesh on which to evaluate the derivative
 * @return the second derivative of the solution, evaluated along given mesh
 */
arma::colvec Schrodinger::psi_second(int n, arma::colvec z){
    arma::vec h_vec = arma::vec(z.n_rows).ones();
    return (psi(n, z + 2*h_vec) - 2*psi(n, z + h_vec) + psi(n, z)) % h_vec.transform([](double z) {return 1 / (z*z);});
}

/**
 * Energy of the solution
 * @param n energy level
 * @param z mesh on which to evaluate the energy
 * @return the estimation of the energy evaluated along given mesh
 */
arma::vec Schrodinger::energy(int n, arma::vec z) {
    Schrodinger sdg;
    arma::vec psi = sdg.psi(n, z);
    return (-pow(sdg.h_bar, 2) / (2*sdg.m) * sdg.psi_second(n, z) + 0.5 * sdg.m * pow(sdg.w, 2) * (z%z%psi)) % psi.transform([](double z) {return 1 / z;});
}

/**
 * Checks the orthonormality for the 11 first energy level
 *
 * Computes integral scalar product between two energy-level solutions using Gauss-Hermit quadrature method.
 * @warning When checking normality, i.e. (psi_n, psi_n) = 1, the results are slightly different than 1 because of physic constant being set to 1. The error margin for normality is thus set to 1.0.
 * @return true if these solutions are orthonormal, false else
 */
bool Schrodinger::orthonormality() {
    #include "../headers/GaussHermitWeights.h"
    for (int p = 0; p <= 10; p++) {
        for (int q = 0; q <= 10; q++) {
            double c1 = sqrt((m*w) / (pi*h_bar)) / (sqrt(pow(2, p+q) * MathTools::factorial(p) * MathTools::factorial(q)));
            double c2 = c1 * sqrt(h_bar / (m*w));
            Hermit hermit(X);
            arma::vec I = W.t() * (hermit.get(p) % hermit.get(q));
            double integral = c2 * I(0);
            if (std::abs(integral - ((p==q) ? 1 : 0)) >= 1)
                return false;
        }
    }
    return true;
}