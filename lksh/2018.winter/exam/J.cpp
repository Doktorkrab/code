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
#include <climits>
using namespace std;

int n;
const int GARBAGE = INT_MAX;
inline void init(){

}

inline void solve(){
	vector<pair<int, int>> automaton;
	automaton.push_back({1, 4});
	if (n == 1){
		automaton.back().second = 3;
	}
	automaton.push_back({2, 2});
	vector<int> terminals = {1, 3};
	automaton.push_back({2, 2});
	vector<int> mods(n);
	for (int i = 0; i < n; i++){
		automaton.push_back({3 + (2 * i) % n, 3 + ((2 * i) + 1) % n});
	}
	cout << automaton.size() << "\n1 2 2 4\n";
	for (int i = 0; i < automaton.size(); i++){
		cout << automaton[i].first + 1 << ' ' << automaton[i].second + 1 << '\n';
	}

}


int main(){
	#ifdef LOCAL
		freopen("J.in", "r", stdin);
		freopen("J.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}