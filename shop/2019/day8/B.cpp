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

#define int int64_t
using ld = long double;
#define double ld

using namespace std;
using cd = complex<double>;
const double PI = acos(-1);

int n;
string s;
vector<cd> fa;
void fft(vector<cd>& a, bool invert){
    int n = (int) a.size();
    if (n == 1)
        return;
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; i * 2 < n; i++){
        a0[i] = a[i * 2];
        a1[i] = a[i * 2 + 1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double angle = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(angle), sin(angle));
    for (int i = 0; i * 2 < n; i++){
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert){
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}
inline void init(){
    n = s.size();
    int N = 1;
    while (N < n)
        N *= 2;
    fa.resize(N);
    for (int i = 0; i < n; i++)
        fa[i] = s[i] - '0';
    while (s.size() != N)
        s.push_back('0');
}

inline void solve(){
    init();
    fft(fa, 0);
    for(cd& i : fa)
        i *= i;
    fft(fa, 1);
    int ans = 0;
    for (int i = 0; i < (int)fa.size(); i += 2){
        if (s[i / 2] == '1')
            ans += (round(fa[i].real()) - 1) / 2;
    }
    cout << ans << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#else
        freopen("duel.in", "r", stdin);
        freopen("duel.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s)
        solve();

}