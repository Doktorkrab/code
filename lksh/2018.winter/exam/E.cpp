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
const int MAXN = 4e6;
int tree[MAXN];
inline void init(){
	fill(tree, tree + MAXN, INT_MAX);
}

int get_min(int v, int l, int r, int vl, int vr) {
    if(vr <= l || r <= vl)
        return INT_MAX;
    if(vl <= l && r <= vr)
        return tree[v];
    int m = (l + r) / 2;
    return min ( get_min(v * 2, l, m, vl, vr), get_min(v * 2 + 1, m, r, vl, vr) );
}

inline void solve(){
	init();
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++){
		int l, r, h;
		cin >> l >> r >> h;
		arr[i] = {l, r};
	}
	int m;
	vector<pair<int, int>> to_sort;
	cin >> m;
	for (int i = 0; i < m;i++){
		int c;
		cin >> c;
		to_sort.push_back({c, i});
	}
	sort(to_sort.begin(), to_sort.end());
	int N = 1;
	// cerr << n << ' ' << m << '\n';
	while (N < m) N *= 2;
	for (int i = 0; i < m; i++){
		tree[N + i] = to_sort[i].second;
		to_sort[i].second = i;
	} 
	for (int i = N - 1; i > 0; i--){
		tree[i] = min(tree[2 * i], tree[2 * i + 1]);
	}
	vector<vector<int>> ans(m);
	for (int i = 0; i < n; i++) {
        pair<int, int> zap = {arr[i].first, 0};
        // cerr << "\t" << zap.first << ' ' << zap.second << '\n';
        auto uk = lower_bound(to_sort.begin(), to_sort.end(), zap);
        // cerr << "\t" << uk - to_sort.begin() << '\n';
        if(uk == to_sort.end()) {
            continue;
        }
        int left = (*uk).second;
        zap = {arr[i].second, m + 1};
        uk = upper_bound(to_sort.begin(), to_sort.end(), zap);
        if(uk == to_sort.begin()) continue;
        uk--;
        int right = (*uk).second;
        if(right < left) continue;
        // cerr << left << ' ' << right << '\n';
        int r = get_min(1, 0, N, left, right + 1);
        // cerr << r << '\n';
        ans[r].push_back(i);
    }
	for (int i = 0; i < m; i++){
		cout << ans[i].size() << " ";
		for (int x : ans[i]) cout << x + 1 << ' ';
		cout << '\n';
	}

}


int main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    solve();

}