#!/usr/bin/env bash

function generateData() {
    echo "
# NumElements Time
10 11.000000
20 19.000000
50 51.000000
100 109.000000
500 616.000000
1000 1492.000000
2000 3635.000000
5000 10936.000000
10000 26286.000000
20000 64098.000000
50000 202719.000000
" > /tmp/_
}

function doPlot() {
    echo "
set key outside top center
set xtics font ',4'
set ytics font ',4'
u=0
plot '/tmp/_' u 1:2 t 'original' w l lw 2,\
'' u 1:(v=\$2-u, u=\$2, v) t 'differencing' w l lw 3
" > /tmp/_.gnuplot
    gnuplot -p -c /tmp/_.gnuplot
}

generateData
doPlot
