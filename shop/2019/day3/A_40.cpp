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

string to_string(const string& s){
    return s;
}
template<typename T>
string to_string(const vector<T>& vec){
    string res;
    res += '{';
    bool is_first = 1;
    for (const T& i : vec){
        if (!is_first)
            res += ", ";
        res += to_string(i);
    }
    res += '}';
    return res;
}

void prn(){
    cout << '\n';
}
template<typename T, typename... Ts>
void prn(const T& t, const Ts&... ts){
    cout << to_string(t) << ' ';
    prn(ts...);

}
#ifdef DEBUG
    template<typename T, typename... Ts>
    void deb() {}
    template<typename T, typename... Ts>
    void deb(const T& t, const Ts&... ts){}
#else
    void deb(){
        cerr << '\n';
    }
    template<typename T, typename... Ts>
    void deb(const T& t, const Ts&... ts){
        cerr << to_string(t) << ' ';
        deb(ts...);
    }
#endif

int n;
unordered_map<int, int64_t> g;
// unordered_map<int, int64_t> min_e;
unordered_map<int, int64_t> cost;
unordered_set<int> used;
inline void init(){
    g.clear();
    // min_e.clear();
    used.clear();
    cost.clear();
}

inline void solve(){
    init();
    int frst = INT_MAX;
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        g[p]++;
        frst = p;
        // min_e[p] = INT_MAX;
        cost[p] = INT_MAX;
    }
    cost[frst] = 0;
    int64_t ans = 0;
    while (1){
        int v = -1, val_v = -1;
        for (auto& [key, val] : cost){
            if (!used.count(key) && (v == -1 || val < val_v)){
                v = key;
                val_v = val;
            }
        }
        if (v == -1)
            break;
        // for (auto& [key, val] : cost){
        //     deb("{", key, val, "}");
        // }
        // deb(cost[v], v);
        ans += cost[v];
        used.insert(v);
        for (auto& [key, val] : cost){
            if (!used.count(key) && val > min(v % key, key % v)){
                // min_e[key] = min(v % key, key % v);
                cost[key] = min(v % key, key % v);
            }
        }
    }
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A_40.in", "r", stdin);
		freopen("A_40.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}