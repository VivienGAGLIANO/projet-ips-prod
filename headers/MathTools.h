#ifndef MATHTOOLS_H
#define MATHTOOLS_H

#include <armadillo> // using tuple for fast Hermit polynom computing

class MathTools {
    public:
        static double integrate(double (double));
        static int factorial(int);
        static std::function<double(double)> differentiate(std::function<double(double)>);
        constexpr static const double h = 1.0e-10;

    private:

    protected:

};

#endif // MATHTOOLS_H
