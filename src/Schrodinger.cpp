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
    return (psi(n, z + h_vec) - psi(n, z)) % ((1 / h*h) * arma::vec(z.n_rows).ones()) - (psi(n, h_vec) - psi(n, h_vec)) % ((1 / h) * (arma::vec(z.n_rows).ones()));
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
 * Checks the orthonormality 
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