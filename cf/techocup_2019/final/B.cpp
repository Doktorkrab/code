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

int n, k;
const int MAXN = 1e3 + 5;
int arr[MAXN];
inline void init(){
	memset(arr, 0, sizeof(int) * MAXN);
}
struct Problem{
	int now, tests, good;
};
inline void solve(){
	init();
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<Problem> have_now;
	int ptr = 0, tested = 0, ans = 0;
	unordered_map<int, int> invokers;
	invokers[0] = k;
	for (int t = 0;; t++){
		// cerr << have_now.size() << ' ' << ptr << '\n';
		if (have_now.empty() && ptr == n)
			break;
		int have = invokers[t];
		while (have > 0 && ptr < n){
			--have;
			have_now.push_back({0, arr[ptr], 0});
			invokers[t + arr[ptr++]]++;
		}
		int score = (int)(1. * tested / n * 100 + 0.5);
		vector<Problem> nxt;
		for (Problem& p : have_now){
			p.now++;
			// cerr << p.now << ' ' << p.tests << ' ' << p.good << '\n';
			if (p.now == score && !p.good){
				p.good = 1;
				ans++;
			}
			if (p.now == p.tests)
				tested++;
			else
				nxt.push_back(p);
		}
		have_now = nxt;
	}
	cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> k)
        solve();

}