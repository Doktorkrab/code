#!/bin/bash

g++ -std=c++14 -O2 genA.cpp -o gen
g++ -std=c++14 -O2 stressA.cpp -o ok

for ((t = 1;; t++))
do
	./gen > test || break
	java -jar day4.jar < test > my_ans || break
	./ok < test > corr_ans || break
	diff -wEZBib corr_ans my_ans || break
	echo  "Ok $t"
done

