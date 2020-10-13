#ifndef SCHRODINGER_H
#define SCHRODINGER_H

/**
 * @file Schrodinger.h
 */

#include <armadillo>

/**
 * Class containing all functions related to Schrödinger's one dimension harmonic oscillator solutions.
 */
class Schrodinger {
    public:
        const double m = 1; /** < Particle's mass */
        const double w = 1; /** < Particle's pulsation*/
        const double pi = 1; /** < Pi */
        const double h_bar = 1; /** < Planck's constant*/
        const double h = 1e-10; /** < Derivation constant */

        arma::colvec psi(int, arma::colvec);
        arma::colvec psi_second(int, arma::colvec);
        arma::colvec energy(int, arma::colvec);
        bool orthonormality();

    private:

};

#endif // SCHRODINGER_H