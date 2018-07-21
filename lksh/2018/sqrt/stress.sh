g++ -O2 -std=c++14 -o gen gen.cpp
g++ -O2 -std=c++14 -o sol c.cpp
g++ -O2 -std=c++14 -o ok ok.cpp

for ((;;)) ; do
    ./gen > test || break
    ./ok < test > corr || break
    ./sol < test > my || break
    diff my corr || break
    echo -n .
done