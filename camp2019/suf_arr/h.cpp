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
#define int int64_t
int n, k;
vector<int> p, c, np, nc, cnt, lcp, pos;
string s;
inline void init(){
    s += '#';
    n = s.size();
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b){return s[a] < s[b];});
    c.resize(n);
    np.resize(n);
    nc.resize(n);
    cnt.resize(n + 1);
    lcp.resize(n);
    pos.resize(n);
}

inline void solve(){
    init();
    int cl = 0;
    for (int i = 0; i < n; i++){
        if (i == 0 || s[p[i]] == s[p[i - 1]])
            c[p[i]] = cl;
        else
            c[p[i]] = ++cl;
    }
    for (int k = 0; (1 << k) < n; k++){
        int pk = (1 << k);
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++)
            cnt[c[i] + 1]++;
        for (int i = 1; i < n; i++)
            cnt[i] += cnt[i - 1];

        for (int i = 0; i < n; i++){
            int j = p[i] - pk;
            if (j < 0)
                j += n;
            np[cnt[c[j]]++] = j;
        }
        cl = 0;
        for (int i = 0; i < n; i++){
            if (i == 0 || make_pair(c[np[i]], c[(np[i] + pk) % n]) == make_pair(c[np[i - 1]], c[(np[i - 1] + pk) % n]))
                nc[np[i]] = cl;
            else
                nc[np[i]] = ++cl;
        }
        swap(np, p);
        swap(nc, c);
    }
    for (int i = 0; i < n; i++)
        pos[p[i]] = i;
    int g = 0;
    for (int i = 0; i < n; i++){
        if (g)
            --g;
        if (pos[i] == n - 1){
            g = 0;
            continue;
        }
        int j = p[pos[i] + 1];
        while (i + g < n && j + g < n && s[i + g] == s[j + g])
            g++;
        lcp[pos[i]] = g;
    }
    for (int i = 1; i < n; i++){
        int now = n - p[i] - lcp[i - 1] - 1;
        if (now < k){
            k -= now;
            continue;
        }
        string ans;
        while (lcp[i - 1] > 0){
            ans += s[p[i]++];
            lcp[i - 1]--;
        }
        while (k > 0){
            ans += s[p[i]++];
            --k;
        }
        cout << ans << '\n';
        return;
    }
    for (int i = p.back(); i < n - 1; i++)
        cout << s[i];
    cout << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("h.in", "r", stdin);
		freopen("h.out", "w", stdout);
	#else
                freopen("kthsubstr.in", "r", stdin);
                freopen("kthsubstr.out", "w", stdout);
        #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s >> k)
        solve();

}
