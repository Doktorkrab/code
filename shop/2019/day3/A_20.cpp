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
#include <random>
#include <chrono>
#define  FMA (int) 1e8
#ifdef FMA
char alloc[FMA];
int alloc_pos = 0;
inline void* operator new(size_t n) noexcept {
    char* res = alloc + alloc_pos;
    alloc_pos += n;
    assert(alloc_pos <= FMA);
    return (void*) res;
}
inline void operator delete(void*) noexcept {}
#endif
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
#define int int64_t
int n;
vector<int> p;
// vector<vector<int>> g;
vector<int64_t> cost, used;
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
inline void init(){
    p.resize(n, -1);
    // g.assign(n, vector<int>());
    cost.resize(n, LLONG_MAX);
    used.resize(n, 0);
    // min_e.resize(n, LLONG_MAX);
}
 
inline void solve(){
    init();
    for (int i = 0; i < n; i++)
        cin >> p[i];
     
    // min_e[0] = 0;
    cost[0] = 0;
    int64_t ans = 0;
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(),p.end()), p.end());
    while (1){
        int v = -1;
        for (int i = 0; i < (int)p.size(); i++){
            if (!used[i] && (v == -1 || cost[v] > cost[i]))
                v = i;
        }
        if (v == -1)
            break;
        // deb(v, cost[v]);
        used[v] = 1;
        ans += cost[v];
        for (int i = 0; i < (int)p.size(); i++){
            int cst = min(p[i] % p[v], p[v] % p[i]); 
            if (!used[i] && cost[i] > cst){
                // min_e[i] = min_e[v] + cst;
                cost[i] = cst;
            }
        }
    }
    cout << ans << '\n';
}
 
 
int32_t main(){
    #ifdef LOCAL
        freopen("A_20.in", "r", stdin);
        freopen("A_20.out", "w", stdout);
    #endif
     
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();
 
}