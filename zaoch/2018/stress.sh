#!/usr/bin/bash
g++ -O2 -std=c++14 -o sol H.cpp
g++ -O2 -std=c++14 -o ok h_slow.cpp
g++ -O2 -std=c++14 -o gen gen.cpp
for ((t = 1;; t++))
do
	./gen > test || break
	./sol < test > my_ans || break
	./ok < test > corr_ans || break
	./checker.py my_ans corr_ans || break
	echo "Test $t ok"
done