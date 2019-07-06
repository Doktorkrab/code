#!/bin/bash

g++ -std=c++14 -O2 gen.cpp -o gen
g++ -std=c++14 -O2 LDEBUG.cpp -o ok
g++ -std=c++14 -O2 J.cpp -o my

for ((t = 1;; t++))
do
	./gen > test || break
	./ok < test > corr_ans || break
	./my < corr_ans > my_ans || break
	diff -wEZBb test my_ans || break
	echo  "Ok $t"
done

