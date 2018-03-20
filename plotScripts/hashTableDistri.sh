#!/usr/bin/env bash

function generateData() {
    echo "
0 1
1 0
2 1
3 1
4 1
5 1
6 0
7 1
8 1
9 1
10 0
11 0
12 1
13 0
14 1
15 1
16 1
17 1
18 0
19 1
20 0
21 1
22 0
23 1
24 0
25 0
26 1
27 1
28 1
29 1
30 0
31 1
32 0
33 1
34 1
35 0
36 1
37 0
38 1
39 1
40 0
41 0
42 0
43 1
44 0
45 0
46 1
47 1
48 0
49 1
" > /tmp/_
}

function doPlot() {
    echo "
plot [0:50][] '/tmp/_' u 1:2 t '' w boxes fs solid 0.5
" > /tmp/_.gnuplot
    gnuplot -p -c /tmp/_.gnuplot
}

generateData
doPlot
