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
const int MAXN = 2e5 + 7;
int t[MAXN];
pair<int, int> lftans[MAXN];
pair<int, int> rgtans[MAXN];
pair<int, int> segments[MAXN];

inline void init() {
    fill(t, t + MAXN, 0);
    fill(segments, segments + MAXN, make_pair(1, -1));
}

pair<int, int> intersect(int l1, int r1, int l2, int r2) {
    return {max(l1, l2), min(r1, r2)};
}

inline void solve() {
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n - 1; i++)
        cin >> segments[i].first >> segments[i].second;

    pair<int, int> lft = {0, 1e9 + 7};
    pair<int, int> rgt = {0, 1e9 + 7};
    lftans[0] = lft;
    for (int i = 1; i < n; i++) {
        lftans[i] = lftans[i - 1];
        if (lftans[i].first > lftans[i].second)
            continue;
        lftans[i] = intersect(lftans[i].first, lftans[i].second, segments[i - 1].first, segments[i - 1].second);
        if (lftans[i].first <= lftans[i].second && lftans[i].first == segments[i - 1].first)
            lftans[i].first -= t[i];
        lftans[i].first = max(0, lftans[i].first);
    }
    rgtans[n - 1] = rgt;
    for (int i = n - 2; i >= 0; i--) {
        rgtans[i] = rgtans[i + 1];
        if (rgtans[i].first > rgtans[i].second)
            continue;
        rgtans[i] = intersect(rgtans[i].first, rgtans[i].second, segments[i].first, segments[i].second);
        if (rgtans[i].first <= rgtans[i].second && rgtans[i].first == segments[i].first)
            rgtans[i].first -= t[i];
        rgtans[i].first = max(0, rgtans[i].first);
    }
    for (int i = 0; i < n; i++) {
        if (rgtans[i].first > rgtans[i].second || lftans[i].first > lftans[i].second)
            cout << "-1\n";
        else {
            auto gg = intersect(lftans[i].first, lftans[i].second, rgtans[i].first, rgtans[i].second);
            if (gg.first > gg.second)
                cout << "-1\n";
            else
                cout << gg.first << '\n';
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    solve();

}