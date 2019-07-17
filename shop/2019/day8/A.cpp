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
using cd = complex<double>;
const double PI = acos(-1);
int n, m, N;
int res = 1;
string s, t;
const int MAXK = 18;

void fft(vector<cd>& a, bool invert){
    int n = (int)(a.size());
    if (n == 1){
        return;
    }
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++){
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1]; 
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2. * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));

    for (int i = 0; i * 2 < n; i++){
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

inline void init(){
    N = 1;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    n = s.size();
    m = t.size();
    if (s.back() == '-'){
        n--;
        res *= -1;
    }
    if (t.back() == '-'){
        --m;
        res *= -1;
    }
    while (N < n + m) N *= 2;
}

inline void solve(){
    init();
    vector<cd> a(N), b(N);
    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';

    for (int i = 0; i < m; i++)
        b[i] = t[i] - '0';
    for(cd i : a)
        cerr << i << '\n';
    cerr << '\n';
    // for (cd i : b)
    //     cerr << i << '\n';
    // cerr << '\n';
    fft(a, 0);
    fft(b, 0);


    for(cd i : a)
        cerr << i << '\n';
    cerr << '\n';
    // for (cd i : b)
    //     cerr << i << '\n';
    // cerr << '\n';

    for (int i = 0; i < N; i++)
        a[i] *= b[i];
    fft(a, 1);

    vector<int> result(N + 1);
    for (int i = 0; i < N; i++)
        result[i] = round(a[i].real());
    // for (int i = 0; i < N; i++)
        // cerr << result[i] << ' ';
    // cerr << '\n';
    for (int i = 0; i < N; i++){
        // cerr << result[i] << ' ';
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
    // cerr << '\n';
    reverse(result.begin(), result.end());
    int i = 0;
    while (i < N && result[i] == 0)
        i++;
    if (res == -1 && result[i] != 0)
        cout << "-";
    // cerr << i << '\n';
    cout << result[i++];
    for (; i <= N; i++){
        cout << result[i];
    }
    cout << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s >> t)
        solve();

}