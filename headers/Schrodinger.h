#ifndef SCHRODINGER_H
#define SCHRODINGER_H

#include <armadillo>

class Schrodinger {
    public:
        arma::cx_double solution(arma::cx_double, int);
        bool orthonormality();
        double energy(int);

    private:

};

#endif SCHRODINGER_H