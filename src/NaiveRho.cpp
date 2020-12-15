#include "../headers/NaiveRho.h"
#include "../headers/Basis.h"


/**
 * Compute atomic density with naive algorithm
 *
 * Algorithm will loop through each and every term of the decomposition along basis function.
 * With given basis, density doesn't depend on theta, so r and z are the only arguments.
 *
 * @param zVals input values for z. Armadillo vector to optimize compute time with Boost library
 * @param rVals input values for r. Armadillo vector to optimize compute time with Boost library
 * @return matrix with atomic density values in cylindrical coordinate system. Z values are along lines, r values along rows.
 */
arma::mat NaiveRho::density(arma::vec zVals, arma::vec rVals) {
    arma::mat rho;
    rho.load("rho.arma", arma::arma_ascii);
    arma::mat result = arma::zeros(zVals.size(), rVals.size()); // number of points on r- and z- axes
    Basis basis(1.935801664793151,      2.829683956491218,     14,     1.3);
    int i = 0;
    int j = 0;
    for (int m = 0; m < basis.mMax; m++)
    {
        for (int n = 0; n < basis.nMax(m); n++)
        {
            for (int n_z = 0; n_z < basis.n_zMax(m, n); n_z++)
            {
                for (int mp = 0; mp < basis.mMax; mp++)
                {
                    for (int np = 0; np < basis.nMax(mp); np++)
                    {
                        for (int n_zp = 0; n_zp < basis.n_zMax(mp, np); n_zp++)
                        {
                            arma::mat funcA = basis.basisFunc( m,  n,  n_z, zVals, rVals);
                            arma::mat funcB = basis.basisFunc(mp, np, n_zp, zVals, rVals);
                            result += funcA % funcB * rho(i, j);
                            i++;
                        }
                    }
                }
                j++;
                i = 0;
            }
        }
    }
    return result;
}