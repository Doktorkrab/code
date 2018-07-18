#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9;
#endif

// -*-*-* All variables *-*-*-
vector<int> p;
string s;
// -*-*-* All functions *-*-*-
void init() {}
bool cmp(int i, int j) {
    int l = i, r = j;
    while (l < (int)s.size() && r < (int)s.size()) {
        if (s[l] == s[r]) {
            l++, r++;
            continue;
        }
        return s[l] < s[r];
    }
    return l == (int)s.size() && r != (int)s.size();
}
void solve() {
    getline(cin, s);
    p.resize(s.size());
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), cmp);
    for (int i : p)
        cout << i + 1 << ' ';
    cout << '\n';
}
int main() {
#ifdef LOCAL
    string taskName = "C";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
#else
    string taskName = "";
// freopen((taskName + ".in").c_str(), "r", stdin);
// freopen((taskName + ".out").c_str(), "w", stdout);
#endif
    solve();
#ifdef LOCAL
    cerr << "Elapsed " << setprecision(4) << fixed
         << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
}