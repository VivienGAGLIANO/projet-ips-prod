#ifndef SCHRODINGER_H
#define SCHRODINGER_H

#include <armadillo>

class Schrodinger {
    public:
        const double m = 1;
        const double w = 1;
        const double pi = 1;
        const double h = 1;

        bool orthonormality();
        double energy(int);

    private:

};

#endif SCHRODINGER_H