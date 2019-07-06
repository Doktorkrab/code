#!/usr/bin/bash
# g++ -O2 -std=c++17 -o gen gen.cpp
# g++ -O2 -std=c++17 -o sol A_100.cpp
# g++ -O2 -std=c++17 -o cor A.cpp
for (( i = 1;; i++ )); do
 	./gen > test || break
 	./sol < test > my_ans || break
 	./cor < test > cor_ans || break
 	diff my_ans cor_ans || break
 	echo "Test $i ok"
 done 