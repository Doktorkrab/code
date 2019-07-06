#include <bits/stdc++.h>
#define ___GLIBCXX_DEBUG
using namespace std;
vector<int> sz, p;
vector<vector<int>> field;
vector<vector<int>> used;
vector<int> have_lower;
unordered_set<int> kek;
int n, m;

int get_par(int v) {
    return p[v] = (p[v] == v ? v : get_par(p[v]));
}

int get_id(int x, int y){
    return x * n + y;
}
void un(int a, int b) {
    a = get_par(a);
    b = get_par(b);
    if (sz[a] > sz[b]) swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
    have_lower[b] |= have_lower[a];
}

vector<pair<int, int>> shift = {{0,  1},
                                {0,  -1},
                                {1,  0},
                                {-1, 0}};

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y) {
    deque<pair<int, int>> q = {{x, y}};
    while (q.size()) {
        auto top = q.front();
        q.pop_front();
        if (used[top.first][top.second]) continue;
        used[top.first][top.second] = 1;
        for (auto sh : shift) {
            if (check(top.first + sh.first, top.second + sh.second) &&
                field[top.first][top.second] == field[top.first + sh.first][top.second + sh.second]) {
                un(get_id(top.first, top.second), get_id(top.first + sh.first, top.second + sh.second));
                q.push_back({top.first + sh.first, top.second + sh.second});
            }
            if (check(top.first + sh.first, top.second + sh.second) &&
                field[top.first][top.second] > field[top.first + sh.first][top.second + sh.second]) {
                have_lower[get_id(top.first, top.second)] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    sz.resize(n * m + 20);
    p.resize(n * m + 20);
    have_lower.resize(n * m + 20);
    field.assign(n, vector<int>(m, 0));
    used.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sz[get_id(i, j)] = 1;
            p[get_id(i, j)] = get_id(i, j);
            cin >> field[i][j];
        }
    }
    int ans = 0;
    for (int i = 0;i < n;i++){
        for (int j = 0; j < m;j++){
            bfs(i, j);
        }
    }
    for (int i = 0;i < n;i++) for (int j = 0;j < m;j++) if (get_par(get_id(i, j)) == get_id(i, j)) ans += !have_lower[get_id(i, j)];
    cout << ans << '\n';
    return 0;
}