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
string s;
inline vector<int> build_array(string s){
    int n = (int) s.size();
    vector<int> p(n), np(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b){ return s[a] < s[b];});
    
    vector<int> c(n), nc(n);
    int cl = 0;
    for (int i = 0; i < n; i++)
        if (i == 0 || s[p[i]] == s[p[i - 1]])
            c[p[i]] = cl;
        else
            c[p[i]] = ++cl;
    
    vector<int> cnt(n + 1);
    for (int k = 0; (1 << k) < n; k++){
        int pk = (1 << k);

        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++)
            cnt[c[i] + 1]++;
        for (int i = 1; i < n; i++)
            cnt[i] += cnt[i - 1];
        
        for (int i = 0; i < n; i++){
            int j = i - pk;
            if (j < 0)
                j += n;
            np[cnt[c[j]]++] = j;
        }
        cl = 0;
        for (int i = 0; i < n; i++){
            if (i == 0 || (make_pair(c[np[i]], c[(np[i] + pk) % n]) == make_pair(c[np[i - 1]], c[(np[i - 1] + pk) % n])))
                nc[np[i]] = cl;
            else
                nc[np[i]] = ++cl;
        }
        swap(np, p);
        swap(nc, c);
    }
    return p;
}
inline void init(){
    n = s.size();
}

inline void solve(){
    init();
    vector<int> suf_arr = build_array(s);
    for (int i : suf_arr)
        cerr << i << ' ';
    cerr << '\n';
    for (int i = 0; i < n; i++){
        if (suf_arr[i] == 0){
            cout << i << '\n';
            break;
        }
    }
}


int main(){
	#ifdef LOCAL
		freopen("d.in", "r", stdin);
		freopen("d.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();

}
