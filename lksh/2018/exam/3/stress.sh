#!/bin/bash

g++ -std=c++14 -O2 gen.cpp -o gen
g++ -std=c++14 -O2 D41.cpp -o sol
g++ -std=c++14 -O2 ok.cpp -o ok

for ((t = 1;; t++))
do
	./gen > test || break
	./sol < test > my_ans || break
	./ok < test > corr_ans || break
	python checker.py || break
	echo "Ok $t"
done