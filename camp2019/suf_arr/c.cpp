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

string s;
int n;

vector<int> suf_arr(string s){
    s += '$';
    int n = s.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b){
            return s[a] < s[b];
    });
    vector<int> c(n), cnt(n + 1);
    int cl = 0;
    for (int i = 0; i < n; i++)
        if (i == 0 || s[p[i]] == s[p[i - 1]])
            c[p[i]] = cl;
        else
            c[p[i]] = ++cl;
    for (int k = 0; (1 << k) < n; k++){
        int pk = (1 << k);
        int tmpk = ((n - pk) % n + n) % n;
        fill(cnt.begin(), cnt.end(), 0);
        vector<int> np(n), nc(n);

        for (int i = 0; i < n; i++)
            ++cnt[c[i] + 1];
        for (int i = 1; i < n; i++)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++){
            int j = (p[i] + tmpk) % n;
            np[cnt[c[j]]++] = j;
        }
        cl = 0;
        for (int i = 0; i < n; i++){
            if (i == 0 || make_pair(c[np[i]], c[(np[i] + pk) % n]) == make_pair(c[np[i - 1]], c[(np[i - 1] + pk + n) % n]))
                nc[np[i]] = cl;
            else
                nc[np[i]] = ++cl;
        }
        swap(nc, c);
        swap(np, p);
    }
    return p;
}
vector<int> build_lcp(vector<int> &arr, string s){
    s += '$';
    int n = s.size();
    vector<int> lcp(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[arr[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++){
        if (k > 0)
            --k;
        if (pos[i] == n - 1){
            lcp[n - 1] = -1;
            k = 0;
            continue;
        }
        int j = arr[pos[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        lcp[pos[i]] = k;
    }
    return lcp;
}
inline void init(){
    n = s.size();
}

inline void solve(){
    init();
    vector<int> arr = suf_arr(s);
    vector<int> lcp = build_lcp(arr, s);
    int64_t sum = 0;
    for (int i = 0; i + 1 < arr.size(); i++)
        sum += lcp[i];
    cout << 1LL * (n + 1) * n / 2 - sum << '\n';
}


int main(){
	#ifdef LOCAL
	#else
                freopen("count.in", "r", stdin);
                freopen("count.out", "w", stdout);
    #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();

}
