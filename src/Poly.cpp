#include "../headers/Poly.h"
#include <iomanip> // hermit << operator formatting

/**
 * @file Poly.cpp
 */



/**
 * Computes and evaluates hermit polynomial
 *
 * This function uses the recursion relation definition of the hermit polynomials to fill the values matrix up to rank n polynomials with the parameter mesh
 * 
 * @param n rank of the desired polynomial
 */
void Poly::calcHermite(int n, arma::vec mesh) {
    if (n < 0) {
        throw "Invalid polynomial index. Positive integers only.";
    }
    this->mesh = mesh;
//    if (!arma::approx_equal(mesh_hermite, mesh, "absdiff", 1E-10)){
//        mesh_hermite = mesh;
//        hermite_values = arma::mat(mesh_hermite.n_elem, 1).ones();
//    }
    hermite_values = arma::mat(mesh.n_elem, 1).ones();
    int m = hermite_values.n_cols;
    while (m <= n) {
        arma::colvec next_col;
        if (m == 1)
            next_col = 2 * mesh;
        else
            next_col = 2*(mesh % hermite_values.col(m - 1)) - 2 * (m - 1) * hermite_values.col(m - 2);
        hermite_values.insert_cols(m, next_col);
        m++;
    }
}


/**
 * Computes and evaluates laguerre polynomial
 *
 * This function uses the recursion relation definition of the laguerre polynomials to fill the values matrix up to rank n polynomials with the parameter mesh
 *
 * @param n rank n of the desired laguerre polynomial
 * @param m rank m of the desired laguerre polynomial
 */
void Poly::calcLaguerre(int m_max, int n_max, arma::vec mesh) {
    if (n_max < 0 || m_max < 0) {
        throw "Invalid polynomial index. Positive integers only.";
    }
    this->mesh = mesh;
    laguerre_values = arma::cube(mesh.n_elem, n_max + 1, m_max + 1);
    for (int m = 0; m <= m_max; m++) {
        arma::mat current_slice = arma::mat(mesh.n_elem, 1).ones();
        int n = current_slice.n_cols;
        while (n <= n_max) {
            arma::colvec next_col;
            if (n == 1)
                next_col = 1 + m - mesh;
            else
                next_col = (2+(m-1-mesh)/n) % current_slice.col(n-1) - (1 + (m-1)/n) * current_slice.col(n-2);
            current_slice.insert_cols(n, next_col);
            n++;
        }
        laguerre_values.slice(m) = current_slice;
    }
}


/**
 * Accessor for n-th hermit polynomial
 *
 * @param n rank of the desired polynomial
 * @return Returns evaluation of n-th polynomial for the object's mesh_hermite
 * @deprecated
 */
arma::vec Poly::hermite(int n) {
    if (n >= (int)hermite_values.n_cols) {
        throw "Values not computed for inputed integer. Run calcHermite first.\n";
    }
    else {
        return hermite_values.col(n);
    }
}

/**
 * Accessor for n-th laguerre polynomial
 *
 * @param n rank n of the desired laguerre polynomial
 * @param m rank m of the desired laguerre polynomial
 * @return Returns evaluation of n-th polynomial for the object's mesh_laguerre
 * @deprecated
 */
arma::vec Poly::laguerre(int m, int n) {
    if (n >= (int)laguerre_values.n_cols || m >= (int)laguerre_values.n_slices) {
        throw "Values not computed for inputed integers. Run calcLaguerre first.\n";
    }
    return laguerre_values.slice(m).col(n);
}
