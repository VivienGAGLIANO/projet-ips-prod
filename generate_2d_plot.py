#!/usr/bin/env python3
import numpy
from matplotlib import pyplot

density = numpy.loadtxt(open("2dplot.csv", "rb"), delimiter=",")

pyplot.matshow(density)
#pyplot.pcolormesh(density)
pyplot.xlabel("z [fm]")
pyplot.ylabel("x [fm]")
pyplot.axis("off")
#pyplot.xlim(-20, 20)
#pyplot.ylim(-10, 10)
pyplot.savefig("2dplot.png")