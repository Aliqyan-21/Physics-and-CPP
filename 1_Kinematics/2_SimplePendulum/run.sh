#!/bin/bash

clear

g++ code.cpp -o code

./code <code.in> Pendulum.out

# gnuplot commands

# plot "Pendulum.dat" u 1:2 w l t "x(t)"
# replot "Pendulum.dat" u 1:3 w l t "y(t)"
# plot "Pendulum.dat" u 1:4 w l t "v_x(t)"
# replot "Pendulum.dat" u 1:5 w l t "v_y(t)"
# plot "Pendulum.dat" u 1:6 w l t "theta(t)"
# replot "Pendulum.dat" u 1:7 w l t "theta'(t)"
# plot [-0.6:0.6][-1.1:0.1] "Pendulum.dat" u 2:3 w l t "x-y"