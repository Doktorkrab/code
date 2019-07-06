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

const int MAXN = 3e5 + 7;
const int MAXLOG = 20;
int n;
int arr[MAXN];
int dp[MAXN];
int rgt[MAXN];
pair<int, int> sp[MAXLOG][MAXN];
int logs[MAXN];
inline void init(){
    memset(arr, 0, sizeof(int) * MAXN);
    fill(dp, dp + MAXN, 0x3f3f3f3f);
    fill(rgt, rgt + MAXN, n);
    for (int i = 2; i < MAXN; i++)
        logs[i] = logs[i / 2] + 1;
}
inline void build(){
    for (int i = 0; i < n; i++)
        sp[0][i] = {arr[i], i};
    for (int log = 1; log < MAXLOG; log++){
        for (int i = 0; i + (1 << log) <= n; i++)
            sp[log][i] = max(sp[log - 1][i], sp[log - 1][i + (1 << (log - 1))]);
    }
}
inline int get_max(int l, int r){
    int len = r - l + 1;
    int log = logs[len];
    return max(sp[log][l], sp[log][r - (1 << log) + 1]).second;
}

inline void solve(){
    init();
    vector<int> stack;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        while (stack.size() && arr[stack.back()] > arr[i]){
            rgt[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }
    build();
    // for (int i = 0; i < MAXLOG; i++)
    //     for (int j = 0; j < n; j++)
    //         cerr << sp[i][j].second << " \n"[j == n - 1];
    // cerr << '\n';
    int l = 0;
    int cnt = 0;
    // for (int i = 0; i < n; i++)
    //     cerr << rgt[i] << " \n"[i == n - 1];
    while (l != n){
        int r = get_max(l, rgt[l] - 1);
        // cerr << l << ' ' << r << ' ' << rgt[l] << '\n';
        l = r + 1;
        cnt++;
    }
    cout << cnt << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}