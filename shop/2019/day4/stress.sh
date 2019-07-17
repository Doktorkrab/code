#!/bin/env bash
g++ -O2 -o corr -std=c++17 h1.cpp
g++ -O2 -o my -std=c++17 H.cpp

for (( i = 1;; i++ )); do
    # ./gen > test || break
    echo $i > test
    ./my < test > my_ans || break
    ./corr < test > corr_ans || break
    diff my_ans corr_ans || break
    echo "Test $i ok"
done