#include <bits/stdc++.h>


using namespace std;


int main(){
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	int n = (rnd() % 50) + 1, q = (rnd() % 49) + 2;
	cout << n << ' ' << q << '\n';
	for (int i = 0; i < q; i++){
		int l = (rnd() % n) + 1;
		int r = (rnd() % n) + 1;
		if (l > r)
			swap(l, r);
		cout << l << ' ' << r << '\n';
	}

}