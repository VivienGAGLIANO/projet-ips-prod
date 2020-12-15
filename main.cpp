/**
 * @file main.cpp
 */

#include <iostream>
#include <armadillo>
#include "headers/NaiveRho.h"
#include "headers/OptimizedRho.h"


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

arma::cube convert_coordinates(arma::mat input, int r_max) {
    int nbp_r = input.n_cols;
    int nbp_z = input.n_rows;
    int x_min = -r_max, x_max = r_max, nbp_x = 32;
    int y_min = -r_max, y_max = r_max, nbp_y = 32;

    arma::cube output = arma::cube(nbp_x, nbp_y, nbp_z).zeros();
    for (int x = 0; x < nbp_x; x++) {
        for (int y = 0; y < nbp_y; y++) {
            for (int z = 0; z < nbp_z; z++) {
//                double real_x = x_min + x * ((x_max - x_min)/nbp_x);
//                double real_y = y_min + y * ((y_max - y_min)/nbp_y);
                double real_x = x_min + (x / x_max) * (x_min / x_max);
                double real_y = y_min + (y / y_max) * (y_min / y_max);
                int r = sqrt(pow(real_x, 2) + pow(real_y, 2));
                if (r >= nbp_r)
                    output(x, y, z) = 0;
                else
                    output(x, y, z) = output(x, y, z) = input(z, r);
            }
        }
    }
    return output;
}


int main() {
    arma::vec zVals = arma::linspace(-20, 20, 64);
    arma::vec rVals = arma::linspace(0, 10, 16);
    arma::cube out = convert_coordinates(OptimizedRho::density(zVals, rVals), 10);

    arma::mat flatview = out.subcube(0, out.n_cols/2, 0, out.n_rows - 1, out.n_cols/2, out.n_slices - 1);
    flatview.save("2dplot.csv", arma::csv_ascii);

    std::ofstream outfile("density.df3");
    outfile << cubeToDf3(out);
    outfile.close();

    return 0;
}