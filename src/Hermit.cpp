#include "../headers/Hermit.h"
#include <iomanip> // hermit << operator formatting

/**
 * Computes and evaluates hermit polynom
 * 
 * This function uses the recursion relation definition of the hermit polynoms to fill the values matrix up to rank n polynoms with the object's mesh 
 * 
 * @param n rank of the desired polynom
 */
void Hermit::hermit(int n) {
    if (n < 0) {
        throw "Invalid polynom index. Positive integers only.";
    }
    int m = hermit_values.n_cols;
    while (m <= n) {
        arma::colvec next_col;
        if (m == 1)
            next_col = 2*mesh;
        else
            next_col = 2*(mesh%hermit_values.col(m-1)) - 2*(m-1)*hermit_values.col(m-2);
        hermit_values.insert_cols(m, next_col);
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
    if ((int) hermit_values.n_cols <= n) {
        hermit(n);
    }
    return hermit_values.col(n);
}

std::ostream& operator<<(std::ostream &stream, const Hermit &hermit) {
    for (int z = 0; z < hermit.hermit_values.n_cols; ++z) {
        for (int n = 0; n < hermit.hermit_values.n_rows; ++n) {
            stream << std::setw(hermit.insert_size) << hermit.hermit_values(n, z) << " ";
        }
        stream << std::endl;
    }
    return stream;
}
