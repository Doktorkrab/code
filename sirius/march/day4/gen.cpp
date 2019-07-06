#include <bits/stdc++.h>

using namespace std;


int main(){
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	cout << (rnd() % 3) + 2 << ' ' << rnd() % 10 << '\n';
}