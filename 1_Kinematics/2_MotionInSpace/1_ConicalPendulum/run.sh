#!/bin/bash

clear

g++ code.cpp -o code

./code <code.in> ConicalPendulum.out

# gnuplot commands

# plot "ConicalPendulum.dat" using 1:2 w l t "x(t)"
# replot "ConicalPendulum.dat" using 1:3 w l t "y(t)"
# replot "ConicalPendulum.dat" using 1:4 w l t "z(t)"

# plot "ConicalPendulum.dat" using 1:5 w l t "v_x(t)"
# replot "ConicalPendulum.dat" using 1:6 w l t "v_y(t)"
# replot "ConicalPendulum.dat" using 1:7 w l t "v_z(t)"

# # For 3D
# splot "ConicalPendulum.dat" u 2:3:4 w l t "r(t)"

# splot [-1.1:1.1][-1.1:1.1][-0.3:0.0] "ConicalPendulum.dat" u 2:3:4 w l t "r(t)"