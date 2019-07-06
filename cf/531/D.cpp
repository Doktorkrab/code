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

int n;
string s;
deque<int> enter[4];
inline void init(){
	for (int i = 0; i < 4; i++)
		enter[i].clear();
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		enter[s[i] - '0'].push_back(i);
	}
	int need = n / 3;
	for (int i = 0; i <= 2; i++){
		int have = 0;
		while (have < need && enter[i].size()){
			have++;
			enter[i].pop_front();
		}
		if (have == need)
			continue;
		while (have < need){
			int cnd = n, ind = -1;
			for (int j = 0; j <= 2; j++){
				if (i == j)
					continue;
				if (i > j && enter[j].size() && cnd > enter[j].front()){
					cnd = enter[j].front();
					ind = j;
				}
				if (i < j && enter[j].size() > need && cnd > enter[j].front()){
					cnd = enter[j].front();
					ind = j;
				}
			}			
			assert(ind != -1);
			have++;
			s[cnd] = i + '0';
			enter[ind].pop_front();
		}
	}
	cout << s << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> s)
        solve();

}