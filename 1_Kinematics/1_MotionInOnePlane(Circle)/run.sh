#!/bin/bash

clear

g++ code.cpp -o code

./code <code.in> Circle.out

# gnuplot commands to plot a graph
# plot "Circle.dat" using 1:2 with lines title "x(t)"
# replot "Circle.dat" using 1:3 with lines title "y(t)"

# plot "Circle.dat" using 1:(atan2($3 - y0, $2 - x0)) with lines title "theta(t)", pi, -pi

# plot "Circle.dat" using 1:4 title "v_x(t)" with lines
# replot "Circle.dat" using 1:5 title "v_y(t)" with lines
# plot "Circle.dat" using 2:3 title "x-y" with lines

