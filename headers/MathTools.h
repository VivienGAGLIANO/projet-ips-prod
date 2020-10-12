#ifndef MATHTOOLS_H
#define MATHTOOLS_H

#include <functional>
#include <armadillo>

class MathTools {
    public:
        static double integrate(double (double));
        static int factorial(int);
        static std::function<double(double)> differentiate(std::function<double(double)>);
        static std::function<arma::colvec(arma::colvec)> differentiate(std::function<arma::colvec(arma::colvec)>);
        constexpr static const double h = 1.0e-10;

    private:

    protected:

};

#endif // MATHTOOLS_H
