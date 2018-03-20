#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4;

int parent[MAXN];
int r[MAXN];

int find_set(int v) {
    return parent[v] == v ? v : (parent[v] = find_set(parent[v]));
}

void _union(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (r[a] < r[b]) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
        if (r[a] == r[b]) r[a]++;
    }
}

int main() {
    // freopen("cutting.in", "r", stdin);
    // freopen("cutting.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> query[k]; // type(0 - cut, 1 - ask), a, b
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        r[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        string type;
        cin >> type >> a >> b;
        query[i] = {type == "ask", a - 1, b - 1};
    }
    vector<int> ans;
    while (k--) {
        int a = query[k][1], b = query[k][2], type = query[k][0];
        if (!type) _union(a, b);
        else ans.push_back(find_set(a) == find_set(b));
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        ans[i] ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}