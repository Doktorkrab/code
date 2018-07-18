#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXN = 10;
#else
const int INF = 1e9;
const int MAXN = 5e5;
#endif

struct Node {
    vector<int> sorted;
};
// -*-*-* All variables *-*-*-
Node t[MAXN]; // [l. r)
int n, m, N;

// -*-*-* All functions *-*-*-

int get(int pos, int tl, int tr, int l, int r, int x) {
    if (tl >= r || l >= tr)
        return 0;
    if (l <= tl && tr <= r)
        return (int)(lower_bound(t[pos].sorted.begin(), t[pos].sorted.end(), x) -
                 t[pos].sorted.begin());
    int tm = (tl + tr) / 2;
    return get(2 * pos, tl, tm, l, r, x) + get(2 * pos + 1, tm, tr, l, r, x);
}

void init() {
    cin >> n >> m;
    int power = 0;
    while ((1 << power) < n)
        power++;
    N = (1 << power);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        t[i + N].sorted = {tmp};
    }
    for (int i = N - 1; i >= 1; i--) {
        int l = 0;
        int r = 0;
        t[i].sorted = {};
        int left_pos = 2 * i, right_pos = 2 * i + 1;
        int left_sz = t[left_pos].sorted.size();
        int right_sz = t[right_pos].sorted.size();
        while (l < left_sz && r < right_sz) {
            if (t[left_pos].sorted[l] < t[right_pos].sorted[r]) {
                t[i].sorted.push_back(t[left_pos].sorted[l]);
                l++;
            } else {
                t[i].sorted.push_back(t[right_pos].sorted[r]);
                r++;
            }
            // cerr << l << ' ' << left_sz << ' ' << r << ' ' << right_sz <<
            // '\n';
        }
        // cerr << l << ' ' << left_sz << ' ' << r << ' ' << right_sz << '\n';
        while (l < left_sz) {
            t[i].sorted.push_back(t[left_pos].sorted[l]);
            l++;
            // cerr << l << " l\n";
        }
        while (r < right_sz) {
            t[i].sorted.push_back(t[right_pos].sorted[r]);
            r++;
            // cerr << r << " r\n";
        }
        // cerr << i << ": ";
        // for (int i : t[i].sorted) cerr << i << ' ';
        // cerr << '\n';
    }
}

void solve() {
    init();
    // cerr << "hereh";
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << get(1, 0, N, a - 1, b, d + 1) - get(1, 0, N, a - 1, b, c)
             << '\n';
    }
}
int main() {
#ifdef LOCAL
    string taskName = "A";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    int t;
    cin >> t;
#else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    int t = 1;
#endif
    while (t--) {
        solve();
#ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed
             << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
#endif
    }
}