#ifndef SCHRODINGER_H
#define SCHRODINGER_H

#include <armadillo>

class Schrodinger {
    public:
        const double m = 1;
        const double w = 1;
        const double pi = 1;
        const double h_bar = 1;
        const arma::vec z = arma::linspace(-100, 100,1000);
        const double h = 1e-10; /** << derivation constant */

        arma::colvec psi(int, arma::colvec);
        arma::colvec psi_second(int, arma::colvec);
        bool orthonormality();
        double energy(int);

    private:

};

#endif // SCHRODINGER_H