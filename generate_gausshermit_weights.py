#!/usr/bin/env python3
import sys
import numpy

DEFAULT_N = 20
GAUSSHERMIT_WEIGHTS_FILE = "headers/GaussHermitWeights.h"

try:
    n = int(sys.argv[1])
except:
    n = DEFAULT_N

X, W = numpy.polynomial.hermite.hermgauss(n)

content = f"""
#ifndef GAUSSHERMIT_WEIGHTS_H
#define GAUSSHERMIT_WEIGHTS_H

#include <armadillo>

arma::colvec X = {{{", ".join([str(x) for x in X])}}};
arma::colvec W = {{{", ".join([str(w) for w in W])}}};

#endif // GAUSSHERMIT_WEIGHTS_H
"""

file = open(GAUSSHERMIT_WEIGHTS_FILE, "w")
file.write(content)
file.close()