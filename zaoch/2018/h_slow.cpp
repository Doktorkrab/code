#include <bits/stdc++.h>

using namespace std;

int get_ans(int x){
	int ret = 1;
	do{
		ret *= x % 10;
		x /= 10;
	}while(x > 0);
	return ret;
}
int main(){
	int l, r;
	cin >> l >> r;
	int ans = get_ans(l), pos = l;
	for (int i = l; i <= r; i++){
		if (ans < get_ans(i)){
			ans = get_ans(i);
			pos = i;
		}
	}
	cout << pos << '\n';
}