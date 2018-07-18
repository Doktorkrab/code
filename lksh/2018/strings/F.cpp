#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int SZ = 42;
const int ABC = 256;
const int N = 5;
#else
const int SZ = 1e3 + 1;
const int INF = 1e9;
const int ABC = 256;
const int N = 101;
#endif
const int BASE_SIZE = 9;
const int BASE = 1e9;
struct Number {
    vector<int64_t> num;

    Number(const string &s) {
        vector<int64_t> tmp;
        string cur;
        int first_block = s.size() % BASE_SIZE;
        int pos = 0;
        if (first_block) {
            for (; pos < first_block; pos++) {
                cur += s[pos];
            }
            tmp.push_back(stoll(cur));
            cur = "";
        }
        for (int i = pos; i < (int)s.size(); i++) {
            cur += s[i];
            if (cur.size() == BASE_SIZE) {
                tmp.push_back(stoul(cur));
                cur = "";
            }
        }
        reverse(tmp.begin(), tmp.end());
        num = tmp;
    }

    Number(int64_t x) : Number(to_string(x)) {}

    int compareTo(const Number &oth) const {
        if (oth.num.size() > num.size()) return -1;
        if (oth.num.size() < num.size()) return 1;
        for (int i = (int)num.size() - 1; i >= 0; i--) {
            if (num[i] < oth.num[i]) return -1;
            if (num[i] > oth.num[i]) return 1;
        }
        return 0;
    }

    Number() {}
    bool operator<(const Number &oth) const {
        return compareTo(oth) == -1;
    }

    bool operator>(const Number &oth) const {
        return compareTo(oth) == 1;
    }

    bool operator==(const Number &oth) const {
        return compareTo(oth) == 0;
    }

    bool operator!=(const Number &oth) const {
        return !(*(this) == oth);
    }

    Number operator+(const Number &oth) const {
        Number c;
        c.num.resize(max(num.size(), oth.num.size()) + 1);
        for (int i = 0; i < (int) max(num.size(), oth.num.size()); i++) {
            if (i < (int)num.size()) c.num[i] += num[i];
            if (i < (int)oth.num.size()) c.num[i] += oth.num[i];
            c.num[i + 1] = c.num[i] / BASE;
            c.num[i] %= BASE;
        }
        if (c.num.back() == 0) c.num.pop_back();
        return c;
    }

    friend ostream &operator<<(ostream &os, const Number &Num) {
        for (int i = (int)Num.num.size() - 1; i >= 0; i--) {
            if (i != (int)Num.num.size() - 1) os << setw(BASE_SIZE) << setfill('0') << abs(Num.num[i]);
            else os << Num.num[i];
        }
        return os;
    }


};
// -*-*-* All variables *-*-*-

int suf[SZ];
int par[SZ];
int pv[SZ];
int parent[SZ];
int link[SZ];
int suplink[SZ];
int term_link[SZ];
int ind[SZ];
int was_term[SZ];
int edges[SZ][ABC];
int go[SZ][ABC];
Number dp[SZ][N];
int is_good[SZ];
bool is_term[SZ];
bool used[SZ], was_here[SZ], ans[SZ];
int first_free = 1, n, m, p;
vector<int> child[SZ];
string abc;
// -*-*-* All functions *-*-*-

void add(const string &s, int pos) {
    int now = 0;
    for (char c : s) {
        if (edges[now][(int)c] == -1) {
            edges[now][(int)c] = first_free;
            pv[first_free] = c;
            parent[first_free++] = now;
            // cerr << first_free << "!!\n";
        }
        now = edges[now][(int)c];
    }
    ind[pos] = now;
    is_term[now] = 1;
}

int make_link(int now) {
    int v = parent[now];
    if (!now){
        return link[now] = 0;
    }
    if (!v){
        return link[v] = 0;
    }
    v = link[v];
    // cerr << now << "!!!\n";
    int c = pv[now];
    while (1) {
        if (edges[v][c] != -1){
            // cerr << v << ' ' << now << ' ' << is_term[v] << '\n';
            if (is_term[edges[v][c]]) term_link[now] = edges[v][c];
            else term_link[now] = term_link[edges[v][c]];
            return link[now] = edges[v][c];
        }
        if (!v)
            return link[now] = 0;
        v = link[v];
    }
}

void build_automate(int now){
    int v = link[now];
    for (int i = 0; i < ABC; i++){
        if (edges[now][i] != -1) go[now][i] = edges[now][i];
        else go[now][i] = go[v][i];
    }
}
void bfs() {
    deque<int> q = {0};
    // cerr << "BFSFSF ";
    while (!q.empty()) {
        // cerr << q.size() << '\n';
        int now = q.front();
        // cerr << now << ' ';
        q.pop_front();
        make_link(now);
        build_automate(now);
        for (int i = 0; i < ABC; i++) {
            if (edges[now][i] != -1)
                q.push_back(edges[now][i]);
        }
    }
    // cerr << '\n';
}

void calc_good(){
    for (int v = 0;v < first_free; v++)
    is_good[v] = !is_term[v] && (term_link[v] == -1);
}

void init() {
    fill(parent, parent + SZ, -1);
    for (int i = 0; i < SZ; i++) {
        fill(edges[i], edges[i] + ABC, -1);
        fill(go[i], go[i] + ABC, 0);
        fill(dp[i], dp[i] + N, 0);
    }
    fill(term_link, term_link + SZ, -1);
}

void solve() {
    init();
    cin >> abc;
    for (int i = 0; i < p; i++) {
        string t;
        cin >> t;
        // cerr << t << '\n';
        add(t, i);
    }
    bfs();
    // for (int i = 0; i < first_free; ++i){
    //     cerr << i << ' ' << link[i] <<":\n";
    //     for (char c : abc){
    //         cerr << "   " << c << ' ' << go[i][c] << ' ' << edges[i][c] << '\n';
    //     }
    //     cerr << '\n';
    // }
    calc_good();
    string s;
    dp[0][0] = 1;
    for (int i = 0; i < m; i++){
        for (int j = 0;j < first_free; j++){
            if (!is_good[j]) {
                dp[j][i] = 0;
                continue;
            }
            for (char c : abc){
                dp[go[j][(int)c]][i + 1] = dp[go[j][(int)c]][i + 1] + dp[j][i];
            }
        }
    }
    Number ans = 0;
    for (int i = 0; i < first_free; i++){
        if (!is_good[i]) {
            dp[i][m] = 0;
            // continue;
        }
        // cerr <<is_good[i] << ' ' <<i << ' ' << dp[i][m] << '\n';
        ans = ans + dp[i][m];
    }
    cout << ans << '\n';
}

signed main() {
#ifdef LOCAL
    string taskName = "F";
    assert(freopen((taskName + ".in").c_str(), "r", stdin));
    assert(freopen((taskName + ".out").c_str(), "w", stdout));
#else
    string taskName = "";
// freopen((taskName + ".in").c_str(), "r", stdin);
// freopen((taskName + ".out").c_str(), "w", stdout);
#endif
    while (cin >> n >> m >> p) {
        solve();
    }
}