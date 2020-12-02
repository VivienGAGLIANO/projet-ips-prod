#include "../headers/Basis.h"
#include "../headers/MathTools.h"
#include "../headers/Poly.h"
#include "math.h"

Basis::Basis(double br, double bz, double N, double Q) : br(br), bz(bz), N(N), Q(Q) {
    int i = 0;
    while (n_zmax_i(i) >= 1) {
        i++;
    }
    this->mMax = (i == 0 ? 0 : i - 1);

    arma::ivec n_Max = arma::ivec(mMax);
    for (int m = 0 ; m < mMax ; m++) {
        n_Max(m) = 0.5 * (mMax - m - 1) + 1;
    }
    this->nMax = n_Max;

    int n = nMax(0);
    arma::imat n_z_Max = arma::imat(mMax,n);
    for (int k = 0 ; k < n ; k++) {
        for (int j = 0 ; j < mMax ; j++) {
            n_z_Max(j, k) = std::max((int)floor(n_zmax_i(j + 2*k + 1)), 0);
        }
    }
    this->n_zMax = n_z_Max;
}

double Basis::n_zmax_i(int i) {
    return (N+2) * pow(Q, 2./3.) + 0.5 - i * Q;
}

arma::vec Basis::rPart(arma::vec r, int m, int n) {
    Poly poly{};
    double cst = (1/(br * sqrt(M_PIl))) * sqrt((double) MathTools::factorial(n) / MathTools::factorial(n + abs(m)));
    arma::vec exp = arma::exp(- r % r / (2 * br * br));
    poly.calcLaguerre(abs(m), n, r % r / (br * br));
    return cst * exp % arma::pow(r / br, abs(m)) % poly.laguerre(abs(m), n);
}

arma::vec Basis::zPart(arma::vec z, int n_z) {
    Poly poly{};
    double cst = 1 / sqrt(bz * pow(2, n_z) * sqrt(M_PIl) * MathTools::factorial(n_z));
    arma::vec exp = arma::exp(- z % z / (2 * bz * bz));
    poly.calcHermite(n_z, z / bz);
    return cst * exp % poly.hermite(n_z);
}

arma::mat Basis::basisFunc(int m, int n, int n_z, arma::vec zVals, arma::vec rVals) {
    return zPart(zVals, n_z) * (rPart(rVals, m, n).t());
}
