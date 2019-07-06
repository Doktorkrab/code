#!/bin/bash

g++ -std=c++14 -O2 gen.cpp -o gen
g++ -std=c++14 -O2 B.cpp -o sol
g++ -std=c++14 -O2 B_slow.cpp -o good

for ((t = 1;; t++))
do
	./gen > test || break
	./sol < test > my_ans || break
	./good < test > corr_ans || break
	diff corr_ans my_ans || break
	echo "Ok $t"
done

