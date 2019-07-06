#include <iostream>
#include <vector>
#include <algorithm>

#define f first
#define s second

using namespace std;

vector<int> tree;
int inf = 1e9;

int get_min(int v, int l, int r, int vl, int vr) {

    if(vr <= l || r <= vl)
        return inf;
    if(vl <= l && r <= vr)
        return tree[v];
    int m = (l + r) / 2;
    return min ( get_min(v * 2, l, m, vl, vr), get_min(v * 2 + 1, m, r, vl, vr) );

}

int main() {

    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> nlo(n);
    for (int i = 0; i < n; i++) {
        cin >> nlo[i].f >> nlo[i].s;
        int h;
        cin >> h;
    }
    int m;
    cin >> m;
    vector<vector<int>> ans(m);
    vector<pair<int, int>> for_sort;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for_sort.push_back({x, i});
    }
    sort(for_sort.begin(), for_sort.end());
    int N = 1;
    while(N < m) N *= 2;
    tree = vector<int>(2 * N, 0);
    for (int i = 0; i < m; i++) {
        tree[N + i] = for_sort[i].s;
        for_sort[i].s = i;
    }
    for (int i = N - 1; i > 0; i--) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    for (int i = 0; i < n; i++) {
        pair<int, int> zap = {nlo[i].f, 0};
        cerr << "\t" << zap.first << ' ' << zap.second << '\n';
        auto uk = lower_bound(for_sort.begin(), for_sort.end(), zap);
        cerr << "\t" << uk - for_sort.begin() << '\n';
        if(uk == for_sort.end()) {
            continue;
        }
        int left = (*uk).s;
        zap = {nlo[i].s, m + 1};
        uk = upper_bound(for_sort.begin(), for_sort.end(), zap);
        if(uk == for_sort.begin()) continue;
        uk--;
        int right = (*uk).s;
        if(right < left) continue;
        cerr << left << ' ' << right << '\n';
        int r = get_min(1, 0, N, left, right + 1);
        ans[r].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i].size() << " ";
        for (auto x : ans[i]) cout << x + 1 << " ";
        cout << '\n';
    }


}
