#!/bin/bash

clear

g++ code.cpp -o code

./code <code.in> ProjectileAirResistance.out

# gnuplot commands

# v0x = 10*cos(pi/4) ; v0y = 10*sin(pi/4)
# g = 9.81 ; k = 5

# plot [:][:v0x/k+0.1] "ProjectileAirResistance.dat" using 1:2 with lines title "x(t)", v0x/k

# replot "ProjectileAirResistance.dat" using 1:3 with lines title "y(t)", -(g/k)*x+(g/k**2)+v0y/k

# plot [:][-g/k-0.6:] "ProjectileAirResistance.dat" using 1:4 with lines title "v_x(t)", 0
# replot "ProjectileAirResistance.dat" using 1:5 with lines title "v_y(t)", -g/k

# plot "ProjectileAirResistance.dat" using 2:3 with lines title "With air resistance k = 5.0"
# replot "ProjectileAirResistance.dat" using 2:3 with lines title "With air resistance k = 0.0"