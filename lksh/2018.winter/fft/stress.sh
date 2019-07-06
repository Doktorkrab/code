#!/bin/bash

g++ -std=c++14 -O2 gen.cpp -o gen
g++ -std=c++14 -O2 A.cpp -o sol

for ((t = 1;; t++))
do
	./gen > test || break
	./sol < test > my_ans || break
	python izi.py < test > corr_ans || break
	diff corr_ans my_ans || break
	echo "Ok $t"
done

