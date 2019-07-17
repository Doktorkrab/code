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
 
int n, m;
const int MAXN = 2e3 + 7;
char arr[MAXN][MAXN];
int h[MAXN][MAXN], lft[MAXN][MAXN], rgt[MAXN][MAXN];
 
inline void init(){
    for (int i = 0; i < MAXN; i++){
        memset(h[i], 0, sizeof(int) * MAXN);
        memset(lft[i], 0, sizeof(int) * MAXN);
        memset(rgt[i], 0, sizeof(int) * MAXN);
    }
}
 
inline void solve(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
 
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == '#')
                h[i][j] = 0;
            else if (i == n - 1)
                h[i][j] = 1;
            else
                h[i][j] = h[i + 1][j] + 1;
 
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cout << h[i][j] << " \n"[j == m - 1];
    // cout << '\n';
    vector<pair<int, int>> stack;
    int64_t ans = 0;
    for (int i = 0; i < n; i++){
        stack.clear();
        for (int j = 0; j < m; j++){
            pair<int, int> now = {h[i][j], j};
            // if (!h[i][j]){
            //     stack.clear();
            //     continue;
            // }
            while (!stack.empty() && stack.back().first >= now.first){
                stack.pop_back();
            }
            // if (h[i][j])
            // deb(stack.size(), i, j);
            // if (stack.size())
            //     deb("\t", stack.back().second);
            if (!stack.empty() && h[i][j])
                lft[i][j] = j - stack.back().second;
            else if (stack.empty() && h[i][j])
                lft[i][j] = j + 1;
            stack.push_back(now);
        }
    }
    for (int i = 0; i < n; i++){
        stack.clear();
        for (int j = m - 1; j >= 0; j--){
            pair<int, int> now = {h[i][j], j};
            // if (!h[i][j]){
            //     stack.clear();
            //     continue;
            // }
            while (!stack.empty() && stack.back().first > now.first)
                stack.pop_back();
            // if (h[i][j])
            // deb(i, j, h[i][j], stack.size(), m - j);
            if (!stack.empty() && h[i][j])
                rgt[i][j] = stack.back().second - j;
            else if (stack.empty() && h[i][j])
                rgt[i][j] = m - j;
            stack.push_back(now);
        }
    }
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cout << lft[i][j] << " \n"[j == m - 1];
 
    // cout << '\n';
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cout << rgt[i][j] << " \n"[j == m - 1];
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int64_t l = lft[i][j];
            int64_t r = rgt[i][j];
            ans += (l * (r - 1) * r / 2 + (l + 1) * l * r / 2) * (h[i][j] * (h[i][j] + 1) / 2);
        }
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
    while (cin >> n >> m)
        solve();
 
}