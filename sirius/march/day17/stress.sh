#!/bin/bash

g++ -std=c++17 -O2 gen.cpp -o gen
g++ -std=c++17 -O2 D_stupid.cpp -o sol
g++ -std=c++17 -O2 D.cpp -o slow
for ((t = 1;; t++))
do
	./gen > test || break
	./sol < test > my_ans || break
	./slow < test > corr_ans || break
	diff corr_ans my_ans || break
	echo "Ok $t"
done

