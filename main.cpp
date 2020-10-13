/**
 * @file main.cpp
 */

#include <iostream>
#include "headers/Schrodinger.h"



int main() {
    int start = -5;
    int end = 5;
    int N = 1000;

    Schrodinger schro;
    arma::vec z = arma::linspace(start, end, N);
    arma::vec psi_z = schro.psi(1, z);

    std::ofstream csv_file;
    csv_file.open("psi.csv");
    csv_file << "z,psi(z)" << std::endl;
    for (int i = 0; i < N; i++) {
        csv_file << z(i) << ',' << psi_z(i) << std::endl;
    }
    csv_file.close();

    return 0;
}