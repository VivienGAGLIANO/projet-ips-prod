/**
 * @file main.cpp
 */

#include <iostream>
#include "headers/Schrodinger.h"

void generate_csv(std::string filename, std::string name, arma::vec z, arma::mat psi) {
    int N = z.n_elem;
    std::ofstream csv_file;
    csv_file.open(filename);
    csv_file << "z";
    for (int n = 0; n < (int) psi.n_cols; n++) {
        csv_file << "," << name << "_" << n << "(z)";
    }
    csv_file << std::endl;
    for (int i = 0; i < N; i++) {
        csv_file << z(i);
        for (int n = 0; n < (int) psi.n_cols; n++) {
            csv_file << ',' << psi(i, n);
        }
        csv_file << std::endl;
    }
    csv_file.close();
}

int main() {
    int start = -5;
    int end = 5;
    int N = 1000;
    int n_max = 10;

    Schrodinger schro;
    arma::vec z = arma::linspace(start, end, N);
    arma::vec psi_z = schro.psi(1, z);

    arma::mat psi;
    arma::mat psi_second;
    arma::mat energy;
    for (int n = 0; n <= n_max; n++) {
        psi.insert_cols(psi.n_cols, schro.psi(n, z));
        psi_second.insert_cols(psi_second.n_cols, schro.psi_second(n, z));
        energy.insert_cols(energy.n_cols, schro.energy(n, z));
    }

    generate_csv("psi.csv", "psi", z, psi);
    generate_csv("psi_second.csv", "psi_second", z, psi_second);
    generate_csv("energy.csv", "E", z, energy);

    return 0;
}