#include <bits/stdc++.h>

using namespace std;


int main(){
	mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
	int l = rnd() % ((int)9e7) + 1;
	int r = rnd() % ((int)9e7) + 1;
	if (l > r)
		swap(l, r);
	cout << l << ' ' << r << '\n';
}