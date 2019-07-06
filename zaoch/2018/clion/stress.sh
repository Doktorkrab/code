
#!/bin/bash

g++ -std=c++14 -O2 gen.cpp -o gen
g++ -std=c++14 -O2 d_mo.cpp -o sol
#g++ -std=c++14 -O2 d_slow.cpp -o ok

for ((t = 1;; t++))
do
	./gen > test || break
	/usr/bin/time ./sol < test > my_ans || break
#	./ok < test > corr_ans || break
#	diff -w my_ans corr_ans || break
done


