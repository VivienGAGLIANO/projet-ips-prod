#ifndef HERMIT_H
#define HERMIT_H

#include <armadillo>


class Hermit {
    public:
        const arma::colvec mesh;
        Hermit(arma::colvec mesh) : mesh(mesh) {
            hermit_values = arma::mat(mesh.n_elem, 1).ones();
        };
        arma::colvec get(int);
    private:
        arma::mat hermit_values;
        void hermit(int);
};


#endif // HERMIT_H