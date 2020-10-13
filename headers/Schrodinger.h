#ifndef SCHRODINGER_H
#define SCHRODINGER_H

#include <armadillo>
#include "GaussHermitWeights.h"

class Schrodinger {
    public:
        const double m = 1;
        const double w = 1;
        const double pi = 1;
        const double h_bar = 1;
        const double h = 1e-10; /** << derivation constant */

        arma::colvec psi(int, arma::colvec);
        arma::colvec psi_second(int, arma::colvec);
        arma::colvec energy(int, arma::colvec);
        bool orthonormality();

    private:

};

#endif // SCHRODINGER_H