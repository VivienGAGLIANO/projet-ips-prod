#include "../headers/OptimizedRho.h"
#include "../headers/Basis.h"


arma::mat OptimizedRho::density(arma::vec zVals, arma::vec rVals) {
    arma::mat rho;
    rho.load("rho.arma", arma::arma_ascii);
    arma::mat result = arma::zeros(zVals.size(), rVals.size()); // number of points on r- and z- axes
    Basis basis(1.935801664793151, 2.829683956491218, 14, 1.3);

    int i = 0;
    arma::icube index(basis.mMax, basis.nMax(0), basis.n_zMax(0, 0), arma::fill::zeros);
    for (int m = 0; m < basis.mMax; ++m) {
        for (int n = 0; n < basis.nMax(m); ++n) {
            for (int n_z = 0; n_z < basis.n_zMax(m, n); ++n_z) {
                index(m, n, n_z) = i;
                i++;
            }
        }
    }
    arma::vec zPart;
    arma::vec rPart;
    for (int m = 0; m < basis.mMax; m++)
    {
        for (int n = 0; n < basis.nMax(m); n++)
        {
            for (int n_z = 0; n_z < basis.n_zMax(m, n); n_z++)
            {
                // Since rho(a, b) = 0 if m_a != m_b, we can remove the for (int m = 0;...) loop
                    for (int np = 0; np < basis.nMax(m); np++)
                    {
                        for (int n_zp = 0; n_zp < basis.n_zMax(m, np); n_zp++)
                        {
                            arma::mat funcA = basis.basisFunc(m, n, n_z, zVals, rVals);
                            arma::mat funcB = basis.basisFunc(m, np, n_zp, zVals, rVals);
                            result += funcA % funcB * rho(index(m, n, n_z), index(m, np, n_zp));
                        }
                    }
            }
        }
    }
    return result;
}
