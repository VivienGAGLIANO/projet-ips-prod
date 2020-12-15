#!/usr/bin/env python3
import numpy
from matplotlib import pyplot

density = numpy.loadtxt(open("2dplot.csv", "rb"), delimiter=",")

pyplot.matshow(density, extent = [-20, 20, -10, 10])
# Uncomment following line to change colors to red/orange/yellow/black
#pyplot.set_cmap('hot')

pyplot.gca().xaxis.tick_bottom()
pyplot.xlabel("z [fm]")
pyplot.ylabel("x [fm]")

bar = pyplot.colorbar()
bar.set_label("density")

pyplot.title("Nuclear density as a function of x and z")

pyplot.savefig("2dplot.png")