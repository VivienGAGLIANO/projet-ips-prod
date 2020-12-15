#ifndef BASIS_H
#define BASIS_H

#include <armadillo>

/**
 * Function basis used for decomposition
 *
 * Class used to compute atomic density by decomposing along the basis vector
 */
class Basis {
    public:
        Basis(double, double, double, double);
        int mMax; /*!< Basis truncation max for first quantum number*/
        arma::ivec nMax; /*!< Basis truncation max for second quantum number. Depends on first quantum number, so type is vector*/
        arma::imat n_zMax; /*!< Basis truncation max for third quantum number. Depends on the two firsts quantum numbers, so type is matrix*/

        arma::vec rPart(arma::vec, int, int);
        arma::vec zPart(arma::vec, int);
        arma::mat basisFunc(int, int, int, arma::vec, arma::vec);

    private:
        double br; /*!< Perpendicular basis deformation parameter*/
        double bz; /*!< Vertical basis deformation parameter*/
        double N; /*!< Basis truncation parameter*/
        double Q; /*!< Basis truncation parameter*/


        double n_zmax_i(int);
};


#endif // BASIS_H