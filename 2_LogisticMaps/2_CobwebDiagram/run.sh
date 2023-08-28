#!/bin/bash

clear

g++ code.cpp -o code

./code <code.in> logistic.out

# gnuplot commands

set size square
f(x) = r*x*(1.0-x)
r = 3.3

plot "trj.dat" u 2:3 w l
replot f(x), f(f(x)), x