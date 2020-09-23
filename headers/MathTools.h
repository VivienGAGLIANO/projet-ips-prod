#ifndef MATHTOOLS_H
#define MATHTOOLS_H

#include <armadillo> // using tuple for fast Hermit polynom computing

class MathTools {
    public:
        static double integrate(double (double));
        static double hermit(int, double);
        static int factorial(int);

    private:
        arma::vec fast_hermit(int, double);

    protected:

};

#endif // MATHTOOLS_H
