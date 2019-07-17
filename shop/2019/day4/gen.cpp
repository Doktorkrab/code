#include <random>
#include <chrono>
#include <iostream>

using namespace std;

int main(){
    mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
    cout << rnd() % 15 << ' ' << rnd() % 10 << '\n';
}