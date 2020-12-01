#include "../headers/Basis.h"
#include "../headers/MathTools.h"
#include "../headers/Poly.h"

Basis::Basis(double br, double bz, double Q, double N) : br(br), bz(bz), Q(Q), N(N) {
    int i = 0;
    while (n_zmax_i(i) >= 1) {
        i++;
    }
    this->mMax = i == 0 ? 0 : i-1;

    std::cout << this->mMax << std::endl;

    arma::vec n_Max = arma::vec(mMax);
    for (int m = 0 ; m < mMax ; m++) {
        n_Max(m) = 0.5 * (mMax - m - 1) + 1;
    }
    this->nMax = n_Max;
    
    int n = nMax[mMax - 1];
    arma::mat n_z_Max = arma::mat(mMax,n);
    for (int j = 0 ; j < mMax ; j++) {
        for (int k = 0 ; k < n ; k++) {
            n_z_Max(j,k) = n_zmax_i(j + 2*k + 1);
        }
    }
    this->n_zMax = n_z_Max;

}

double Basis::n_zmax_i(int i) {
    return (N+2) * pow(Q,2/3) + 1/2 - i * Q;
}

arma::vec Basis::zPart(arma::vec z, int n_z){
    Poly poly{};
    double cst = 1 / sqrt(bz * pow(2, n_z) * sqrt(M_PIl) * MathTools::factorial(n_z));
    arma::vec exp = arma::exp(- z % z / (2 * bz * bz));
    poly.calcHermite(n_z, z / bz);
    return exp % poly.hermite(n_z) * cst;
}