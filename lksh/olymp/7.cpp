#include <bits/stdc++.h>

#define int long long
#define double long double

using namespace std;

const int MAXN = 1e3 + 10;

vector<int> h(MAXN);
vector<int> ph(MAXN);


signed main() {

    int cnt = 0;

    int n;
    cin >> n;

    h[1] = 9;

    for (int i = 2; i < 100; ++i) {
        h[i] = h[i - 1] * 10;
    }

    for (int i = 0; i < 100; ++i) {
        ph[i * 2] = h[i];
        ph[i * 2 - 1] = h[i];
    }

    int i = 1;
    for (;;++i) {
        if (n - ph[i] <= 0) {
            break;
        } else {
            n -= ph[i];
        }
    }

    int k = pow(10, (i - 1) / 2) - 1;
    while(n != 0) {
        ++k;
        --n;
    }
    if (i & 1) {
        cout << k;
        string p = to_string(k / 10);
        assert(p.begin() != p.end());
        if (p.size())
            reverse(p.begin(), p.end());
        

    } else {
        cout << k;
        string p = to_string(k);
        assert(p.begin() != p.end());
        reverse(p.begin(), p.end());
        cout << p;
    }
    cerr << "JOPA";
    return 0;
}
