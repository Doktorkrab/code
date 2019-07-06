#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

int n, x;

inline void init(){

}

inline void solve(){
	int blocks = (n + 1) / 2;
	if ((blocks & 1) ^ (x & 1) || n < x){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	if (n == 3 && x == 2){
		cout << "2 1\n3 1\n";
		return;
	}
	set<int> kek;
	for (int i = 0; i < n; i++)
		kek.insert(i + 1);
	kek.erase(x);
	multiset<int> kek2;
	while (kek.size() > 1){
		int top = *kek.rbegin();
		kek.erase(top);
		int top1 = *kek.rbegin();
		kek.erase(top1);
		cout << top << ' ' << top1 << '\n';
		kek2.insert(top - top1);
	}
	if (kek.size())
		kek2.insert(*kek.rbegin());
	while (kek2.size() > 1){
		int top = *kek2.rbegin();
		kek2.erase(kek2.find(top));
		int top1 = *kek2.rbegin();
		kek2.erase(kek2.find(top1));
		cout << top << " " << top1 << '\n';
		kek2.insert(top - top1);
	}
	if (kek2.size() && x > 0)
		cout << x << " " << *kek2.rbegin() << '\n';

}


int main(){
	#ifdef LOCAL
		// freopen("A_100.in", "r", stdin);
		// freopen("A_100.out", "w", stdout);
	#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (cin >> n >> x)
        solve();

}