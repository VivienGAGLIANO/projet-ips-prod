#!/bin/bash
if [ ! -f "main" ]; then
    make
fi
./main
./generate_2d_plot.py
povray visu.pov