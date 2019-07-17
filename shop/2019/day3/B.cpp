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
#include <numeric>

using namespace std;

string to_string(const string& s){
    return s;
}
template<typename T, typename S>
string to_string(const pair<T, S>& x){
    return "(" + to_string(x.first) + ", " + to_string(x.second) + ")";
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
inline void init(){

}
inline void solve(){
    int ans = 0;
    set<vector<pair<int, int>>> hh;
    for (int mask = 0; mask < (1LL << (n * (n + 1))); mask++){
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (__gcd(i + 1, j + 1) != 1 || i >= j)
                    continue;
                if ((mask & (1 << (n + 1) * i)) && (mask & (1 << ((n + 1) * i + j + 1))))
                    pairs.emplace_back(i + 1, j + 1);
            }
        }
        bool fl = 0;
        if (pairs.empty())
            continue;
        sort(pairs.begin(), pairs.end());
        if (hh.count(pairs) || pairs.empty())
            continue;
        // prn(pairs, hh.count(pairs));
        hh.insert(pairs);
        for (int x = 2; x <= n; x++){
            bool flag = 1;
            for (auto [a, b] : pairs)
                flag &= (a < x && b < x) || (a >= x && b >= x);
            fl |= flag;
            // cout << flag << ' ' << x << '\n';
        }
        if (!fl){
            ans++;
        }
    }
    cout << ans << ", ";
    cerr << n << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}