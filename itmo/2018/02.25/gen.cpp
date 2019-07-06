#include <bits/stdc++.h>

using namespace std;

int main(){
	srand(time(NULL));
	int n = 8;
	int k = rand() % 5;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
	mt19937 rnd(time(NULL));
	shuffle(arr.begin(), arr.end(), rnd);
	cout << n << ' ' << k << '\n';
	for (int i = 0; i < n; i++)
		cout << arr[i] << " \n"[i == n - 1];
}