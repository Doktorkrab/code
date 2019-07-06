#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
	for (int f = 2; f * f <= n; f++)
		if (n % f == 0)
			return 0;
	return 1;
}

int main(){
	cout << 1 << '\n';
	srand(time(0));
	int m = rand() % ((int)1e1) + 1;
	while (!is_prime(m)){
		m++;
	}
	int a = rand() % 5, b = rand() % 5;
	while (a == 0 && b == 0){
		a = rand() % 5, b = rand() % 5;
	}
	cout << a << ' ' << b << ' ' << m << '\n';
}