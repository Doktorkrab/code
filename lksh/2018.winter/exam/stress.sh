#!/bin/bash

g++ -std=c++14 -O2 gen.cpp -o gen
g++ -std=c++14 -O2 K.cpp -o K
g++ -std=c++14 -O2 K1.cpp -o K1

for ((t = 1;; t++))
do
	./gen > test || break
	./K < test > my_ans || break
	./K1 < test > corr_ans || break
	diff corr_ans my_ans || break
	echo "Ok $t"
done

