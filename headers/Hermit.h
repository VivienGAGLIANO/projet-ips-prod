#ifndef HERMIT_H
#define HERMIT_H

#include <armadillo> // using tuple for fast Hermit polynom computing


class Hermit {
    public:
        const arma::colvec mesh;
        Hermit(arma::colvec mesh) : mesh(mesh) {
            hermit_values = arma::mat(mesh.n_elem, 1).ones();
        };
        arma::colvec get(int);
        int insert_size = 5;

    private:
        arma::mat hermit_values;
        void hermit(int);
        friend std::ostream& operator<<(std::ostream&, const Hermit&);
};


#endif // HERMIT_H