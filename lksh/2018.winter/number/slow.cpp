#include <bits/stdc++.h>

using namespace std;



int main(){
	int l, r;
	while (cin >> l >> r){
		int64_t sum = 0;
		for (int x = l; x <= r; x++){
			sum += x + 1;
			for (int i = 2; i * i <= x; i++){
				if (x % i == 0){
					sum += i + x / i;
					sum -= i * (x / i == i);
					// cout << i << ' ' << x / i << '\n'; 
				}
			}
		}
		cout <<sum << '\n';
	}
}