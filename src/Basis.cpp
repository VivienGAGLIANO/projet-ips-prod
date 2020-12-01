#include "../headers/Basis.h"

Basis::Basis(double br, double bz, double Q, double N) : br(br), bz(bz), Q(Q), N(N) {
    int i = 0;
    while (n_zmax_i(i) < 1) {
        i += 1;
    }
    this->mMax = i;

    arma::vec n_Max = arma::vec(mMax);
    for (int j = 0 ; j < mMax ; j++) {
        n_Max(j) = 0.5 * (mMax - j -1) + 1;
    }
    this->nMax = n_Max;
    
    int n = nMax[mMax];
    arma::mat n_z_Max = arma::mat(mMax,n);
    for (int j = 0 ; j < mMax ; j++) {
        for (int k = 0 ; k < n ; k++) {
            n_z_Max(j,k) = n_zmax_i(j + 2*k);
        }
    }
    this->n_zMax = n_z_Max;

}

double Basis::n_zmax_i(int i) {
    return (N+2) * pow(Q,2/3) + 1/2 - i * Q;
}