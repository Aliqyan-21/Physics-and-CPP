#!/bin/bash

clear

g++ code.cpp -o code

./code <code.in> Lissajous.out

# gnuplot commands

# plot "Lissajous.dat" using 1:2 w l t "x(t)"
# replot "Lissajous.dat" using 1:3 w l t "y(t)"

# plot "Lissajous.dat" using 1:4 w l t "v_x(t)"
# replot "Lissajous.dat" using 1:5 w l t "v_y(t)"

# plot "Lissajous.dat" using 2:3 w l t "x-y for 3:5"