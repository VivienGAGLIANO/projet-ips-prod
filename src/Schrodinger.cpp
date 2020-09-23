#include "../headers/Schrodinger.h"
#include "../headers/MathTools.h"
#include <cmath>

/**
 * @file Schrodinger.cpp
 */



/**
 * Solution of the Schrodinger equation
 * 
 * @param n
 * @param z
 */
double Schrodinger::solution(int n, double z) {
    return (1 / sqrt(pow(2, n) * MathTools::factorial(n))) * pow((m*w)/(pi*h), 0.25) * exp(-m*w*z*z / (2*h)) * MathTools::hermit(n, sqrt(m*w/h) * z);
}
