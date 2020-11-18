#ifndef HERMIT_H
#define HERMIT_H

/**
 * @file Poly.h
 */


#include <armadillo> // using tuple for fast Poly polynomial computing

/*
 * Polynomials class
 *
 * Class used to compute and evaluate calcHermite and laguerre polynomials.
 * Objects of this class must be initiated with a mesh_hermite, an `arma::colvec` on which to evaluate the polynomials. This mesh_hermite CANNOT BE CHANGED after object instantiation.
 */
class Poly {
    public:
        Poly(){};
        void calcHermite(int, arma::vec);
        arma::vec hermite(int);/*!< Getter for Hermite polynomials values.*/
        int insert_size = 5; /*!< Sets the cell size for << operator.*/

    private:
        arma::colvec mesh_hermite; /*!< Mesh on which polynomials of this instance are evaluated. Cannot be changed.*/
        arma::mat hermite_values; /*!< Matrix in which calcHermite evaluation are stored. */
        friend std::ostream& operator<<(std::ostream&, const Poly&);
};


#endif // HERMIT_H