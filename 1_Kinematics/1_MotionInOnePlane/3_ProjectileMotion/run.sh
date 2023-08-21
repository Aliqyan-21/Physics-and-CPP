#!/bin/bash

clear

g++ code.cpp -o code

./code <code.in> Projectile.out

# gnuplot commands

# plot "Projectile.dat" u 1:2 w l t "x(t)"
# replot "Projectile.dat" u 1:3 w l t "y(t)"
# plot "Projectile.dat" u 1:4 w l t "v_x(t)"
# replot "Projectile.dat" u 1:5 w l t "v_y(t)"
# plot "Projectile.dat" u 2:3 w l t "x-y"