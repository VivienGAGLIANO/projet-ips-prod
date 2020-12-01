#ifndef BASIS_H
#define BASIS_H

#include <armadillo>

class Basis{
    public:

    private:
        double br;
        double bz;
        double Q;
        double N;
        int mMax;
        arma::vec nMax;
        arma::mat n_zMax;
        Basis(double, double, double, double);
        double n_zmax_i(int);

};


#endif