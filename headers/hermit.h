#ifndef HERMIT_H
#define HERMIT_H

#include<armadillo>


class Hermit {
    public:
        const arma::rowvec mesh;
        Hermit(arma::rowvec mesh) : mesh(mesh) {
            hermit_values = arma::mat(1, mesh.n_elem).ones();
        };
        arma::rowvec get(int);
    private:
        arma::mat hermit_values;
        void hermit(int);
};


#endif // HERMIT_H