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
    mesh_hermite = mesh;
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
void Poly::calcLaguerre(int m, int n, arma::vec mesh) {
    if (n < 0 || m < 0) {
        throw "Invalid polynomial index. Positive integers only.";
    }
    mesh_laguerre = mesh;
    m_laguerre = m;
    laguerre_values = arma::mat(mesh.n_elem, 1).ones();
    int p = laguerre_values.n_cols;
    while (p <= n) {
        arma::colvec next_col;
        if (p == 1)
            next_col = laguerre_values.col(0) + m - mesh;
        else
            next_col = (2 + (m-1-mesh)/p) % laguerre_values.col(p-1) - (1 + (m - 1)/p) * laguerre_values.col(p-2);
        laguerre_values.insert_cols(p, next_col);
        p++;
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
    if (n >= (int)laguerre_values.n_cols) {
        throw "Values not computed for inputed integer. Run calcLaguerre first.\n";
    }
    if (m != m_laguerre) {
        calcLaguerre(m, std::max(n, (int) laguerre_values.n_cols - 1), mesh_laguerre);
    }
    return laguerre_values.col(n);
}


/**
 * << operator to print hermit object on stdout stream
 *
 * Prints out the hermite_values matrix, showing all computed ranks of polynomials, along the object's mesh_hermite. Use Poly::insert_size to set matrix cells size.
 * @param stream stream on which to add hermit print
 * @param hermit object to print
 * @return stream with hermite_values matrix printed on it
 */
std::ostream& operator<<(std::ostream &stream, const Poly &hermit) {
    for (int z = 0; z < (int) hermit.hermite_values.n_cols; ++z) {
        for (int n = 0; n < (int) hermit.hermite_values.n_rows; ++n) {
            stream /*<< std::setfill('.')*/ << std::setw(hermit.insert_size) << hermit.hermite_values(n, z) << " ";
        }
        stream << std::endl;
    }
    return stream;
}