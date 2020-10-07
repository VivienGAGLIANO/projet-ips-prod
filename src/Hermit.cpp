#include "../headers/Hermit.h"


// /**
//  * 
//  */
// Hermit::Hermit(arma::rowvec mesh) : mesh(mesh) {
//     hermit_values = arma::mat(1, mesh.n_elem, double).ones();
// }

/**
 * Computes and evaluates hermit polynom
 * 
 * This function uses the recursion relation definition of the hermit polynoms to fill the values matrix up to rank n polynoms with the object's mesh 
 * 
 * @param n rank of the desired polynom
 */
void Hermit::hermit(int n) {
    int m = hermit_values.n_rows;
    while (m < n) {
        arma::rowvec next_row;
        if (m == 1)
            next_row = 2*mesh;
        else
            next_row = 2*(mesh%hermit_values.row(m-1)) - 2*(m-1)*hermit_values.row(m-2);
        hermit_values.insert_rows(m, next_row);
        m++;
    }
}
    

/**
 * Accessor for n-th hermit polynom
 * 
 * @param n rank of the desired polynom
 * @return Returns evaluation of n-th polynom for the object's mesh
 */
arma::rowvec Hermit::get(int n) {
    if ((int) hermit_values.n_rows < n) {
        hermit(n);
    }
    return hermit_values.row(n);
}