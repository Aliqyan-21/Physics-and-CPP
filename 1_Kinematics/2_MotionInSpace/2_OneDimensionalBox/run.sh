#!/bin/bash

clear

g++ code.cpp -o code

./code <code.in> OneDimensionalBox.out

# gnuplot commands

# plot "OneDimensionalBox.dat" u 1:2 w l t "x(t)", 0 notitle, 10 notitle
# plot [:][-1.2:1.2] "OneDimensionalBox.dat" u 1:3 w l t "v(t)"