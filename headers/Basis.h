#ifndef BASIS_H
#define BASIS_H

#include <armadillo>

class Basis {
    public:
        Basis(double, double, double, double);
        int mMax;
        arma::vec nMax;
        arma::mat n_zMax;

        arma::vec rPart(arma::vec, int, int);
        arma::vec zPart(arma::vec, int);

    private:
        double br;
        double bz;
        double N;
        double Q;


        double n_zmax_i(int);
};


#endif // BASIS_H