#include "../headers/Hermit.h"


/**
 * Computes and evaluates hermit polynom
 * 
 * This function uses the recursion relation definition of the hermit polynoms to fill the values matrix up to rank n polynoms with the object's mesh 
 * 
 * @param n rank of the desired polynom
 */
void Hermit::hermit(int n) {
    int m = hermit_values.n_cols;
    while (m <= n) {
        arma::colvec next_col;
        if (m == 1)
            next_col = 2*mesh;
        else
            next_col = 2*(mesh%hermit_values.col(m-1)) - 2*(m-1)*hermit_values.col(m-2);
        std::cout << "avant ";
        hermit_values.insert_cols(m, next_col);
        std::cout << "après : " << hermit_values.n_cols << "\n";
        m++;
    }
}
    

/**
 * Accessor for n-th hermit polynom
 * 
 * @param n rank of the desired polynom
 * @return Returns evaluation of n-th polynom for the object's mesh
 */
arma::colvec Hermit::get(int n) {
    if ((int) hermit_values.n_cols < n) {
        hermit(n);
    }
    return hermit_values.col(n);
}