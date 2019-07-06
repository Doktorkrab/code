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
#define int int64_t
int n;
const int MAXN = 1e5 + 7;
int x[MAXN];
int x2[MAXN];
int dp[MAXN];
int dp_tmp[2][MAXN];
int t, e;
template<typename T>
struct Queue{
    int sz = 0;
    vector<pair<T, T>> stack, stack1;
    void push(const T& x){
        sz++;
        if (stack.empty())
            stack.push_back({x, x});
        else
            stack.push_back({x, min(stack.back().second, x)});
    }
    T get_min(){
        assert(!stack.empty() || !stack1.empty());
        if (stack.empty())
            return stack1.back().second;
        if (stack1.empty())
            return stack.back().second;
        return min(stack.back().second, stack1.back().second);
    }

    T pop(){
        if (!stack1.empty()){
            sz--;
            T ret = stack1.back().first;
            stack1.pop_back();
            return ret;
        }
        while (!stack.empty()){
            T back = stack.back().first;
            stack.pop_back();
            if (stack1.empty())
                stack1.push_back({back, back});
            else
                stack1.push_back({back, min(stack1.back().second, back)});
        }
        assert(!stack1.empty());
        return pop();
    }
};
inline void init(){
    memset(dp, 0x3f, sizeof(int) * MAXN);
}

inline void solve(){
    init();
    for (int i = 1; i <= n; i++){
        cin >> x[i];
        x2[i] = x[i] * 2;
    }
    dp[0] = 0;
    dp_tmp[0][0] = - 2 * x[1];
    dp_tmp[1][0] = t;
    x[0] = 0;
    int l = 0, mn = LLONG_MAX / 2;
    Queue<int> kek;
    kek.push(dp_tmp[1][0]);
    for (int i = 1; i <= n; i++){
        dp[i] = x[i] - x[i - 1] + t + dp[i - 1];
        while (l < i && t - 2 * (x[i] - x[l + 1]) <= 0){
            kek.pop();
            mn = min(mn, dp_tmp[0][l++]);
        }
        dp[i] = min(dp[i], mn + 3 * x[i]);
        if (kek.sz > 0)
            dp[i] = min(dp[i], kek.get_min() + x[i]);
        dp_tmp[0][i] = dp[i] - x[i] - 2 * x[i + 1];
        kek.push(dp[i] - x[i] + t);
    }
    cout << dp[n] + e - x[n] << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> e >> t)
        solve();

}