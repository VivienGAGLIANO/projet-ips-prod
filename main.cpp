/**
 * @file main.cpp
 */

#include <iostream>
#include <armadillo>
#include "headers/Basis.h"
#include "headers/NaiveRho.h"


std::string cubeToDf3(const arma::cube &m)
{
    std::stringstream ss(std::stringstream::out | std::stringstream::binary);
    int nx = m.n_rows;
    int ny = m.n_cols;
    int nz = m.n_slices;
    ss.put(nx >> 8); ss.put(nx & 0xff);
    ss.put(ny >> 8); ss.put(ny & 0xff);
    ss.put(nz >> 8); ss.put(nz & 0xff);
    double theMin = 0.0;
    double theMax = m.max();
    for (uint k = 0; k < m.n_slices; k++)
    {
        for (uint j = 0; j < m.n_cols; j++)
        {
            for (uint i = 0; i < m.n_rows; i++)
            {
                uint v = 255 * (fabs(m(i, j, k)) - theMin) / (theMax - theMin);
                ss.put(v);
            }
        }
    }
    return ss.str();
}

arma::cube convert_coordinates(arma::mat input) {
    int x_min = -10, x_max = 10, nbp_x = 32;
    int y_min = -10, y_max = 10, nbp_y = 32;
    int z_min = -20, z_max = 20, nbp_z = 64;
    double r_max = sqrt(201); int nbp_r = input.n_cols;

    arma::cube output = arma::cube(nbp_x, nbp_y, nbp_z).zeros();
    for (int x = 0; x < nbp_x; x++) {
        for (int y = 0; y < nbp_y; y++) {
            for (int z = 0; z < nbp_z; z++) {
                double real_x = x_min + x * ((x_max - x_min)/nbp_x);
                double real_y = y_min + y * ((y_max - y_min)/nbp_y);
                double r = sqrt(pow(real_x, 2) + pow(real_y, 2));
                output(x, y, z) = input(floor(z * (input.n_rows / nbp_z)), floor((r/r_max) * nbp_r));
            }
        }
    }
    return output;
}

int main() {
/*    arma::cube density = arma::cube(5,10,20).ones();
    for (int x = 0; x<5; x++) {
        for (int y = 0; y<10; y++) {
            for (int z = 0; z<20; z++) {
//                density(x, y, z) = ((double) x+y)/1000.; //z/20;
                density(x, y, z) = 0.1;
            }
        }
    }*/

    arma::vec rVals(16);
    for (int i = 0; i < 16; ++i) {
        rVals(i) = ((double) 10 * i / 16)*1E-15;
    }
    arma::vec zVals(64);
    for (int i = 0; i < 64; ++i) {
        zVals(i) = ((double) 40 * i / 64 - 20)*1E-15;
    }
    arma::cube out = convert_coordinates(NaiveRho::density(zVals, rVals));

    std::ofstream outfile("density.df3");
    outfile << cubeToDf3(out);
    outfile.close();
    return 0;
}