#ifndef MATHTOOLS_H
#define MATHTOOLS_H

#include <armadillo> // using tuple for fast Hermit polynom computing

class MathTools {
    public:
        double integrate(double (double));
        double hermit(int, double);

    private:
        arma::vec fast_hermit(int, double);

    protected:

};

#endif // MATHTOOLS_H