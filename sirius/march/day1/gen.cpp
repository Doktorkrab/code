#include <bits/stdc++.h>


using namespace std;

int main(){
	mt19937 rnd(time(0));
	int n = rnd() % 49 + 1;
	for (int i = 0; i < n; i++)
		cout << rnd() % 2;
	cout << '\n';
}