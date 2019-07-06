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
const int MAXN = 8;
vector<int> g[MAXN];
int used[MAXN];
inline void init(){

}
vector<int> arr;
vector<int> rev;
int dfs(int v){
    used[v] = 1;
    for (int u : g[v]){
        if (rev[u] > rev[v])
            return 0;
        if (!used[u])
            dfs(u);
    }
    return 1;
}
int check(int a, int b){
    memset(used, 0, sizeof(int) * MAXN);
    dfs(a);
    return used[b];
}
inline void solve(){
    arr.resize(n);
    rev.resize(n);
    iota(arr.begin(), arr.end(), 0);
    for (int i = 1; i < n; i++){
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
    }
    int ans = 0;
    do{
        int good = 1;
        memset(used, 0, sizeof(int) * MAXN);
        for (int i = 0; i < n; i++)
            rev[arr[i]] = i;
        for (int i = 0; i < n; i++){
            memset(used, 0, sizeof(int) * MAXN);
            good &= dfs(i);
        }
        ans += good;
    } while (next_permutation(arr.begin(), arr.end()));
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("e.in", "r", stdin);
		freopen("e.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
