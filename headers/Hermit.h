#ifndef HERMIT_H
#define HERMIT_H

/**
 * @file Hermit.h
 */


#include <armadillo> // using tuple for fast Hermit polynom computing

/*
 * Hermite polynomials class
 *
 * Class used to compute and evaluate hermite polynomials.
 * Objects of this class must be initiated with a mesh, an `arma::colvec` on which to evaluate the polynomials. This mesh CANNOT BE CHANGED after object instantiation.
 */
class Hermit {
    public:
        const arma::colvec mesh; /*!< Mesh on which polynomials of this instance are evaluated. Cannot be changed.*/
        /**
         * Constructor for Hermit objects
         *
         * @param mesh the mesh that will be attributed to the instantiated object
         */
        Hermit(arma::colvec mesh) : mesh(mesh) {
            hermit_values = arma::mat(mesh.n_elem, 1).ones();
        };
        arma::colvec get(int);
        int insert_size = 5; /*!< Sets the cell size for << operator.*/

    private:
        arma::mat hermit_values; /*!< Matrix in which hermite evaluation are stored. */
        void hermit(int);
        friend std::ostream& operator<<(std::ostream&, const Hermit&);
};


#endif // HERMIT_H